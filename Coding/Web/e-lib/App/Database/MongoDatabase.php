<?php
namespace App\Database;

use MongoDB\Database;
use App\Integration\Database\MongoConnectionFactory;
use Exception;

class MongoDatabase extends MongoConnectionFactory implements DatabaseInterface {
    /**
     * @var Database
     */
    protected $db;
    
    /**
     * Constructor 
     *
     * @param Database $database A MongoDB Database instance or null for auto-connect
     */
    public function __construct()
    {
        $this->db = self::create('mongo', [
            'dbName' => 'LibraryDb',
            'fallback' => true
        ]);
    }
    
    public function insert(string $collection, array $data): array {
        try {
            $result = $this->db->selectCollection($collection)->insertOne($data);
            return ['insertedId' => (string)$result->getInsertedId()];
        } catch (Exception $e) {
            echo("MongoDB Insert Error: " . $e->getMessage());
            return ['error' => $e->getMessage()];
        }
    }

    public function find(string $collection, array $filter = [], array $options = []): array {
        try {
            // Default options for pagination
            $defaultOptions = [
                'limit' => 100  // Limit results to prevent memory issues
            ];
            
            // Merge with user provided options
            $options = array_merge($defaultOptions, $options);
            
            $cursor = $this->db->selectCollection($collection)->find($filter, $options);
            
            // Process results in batches to avoid memory issues
            $results = [];
            foreach ($cursor as $document) {
                $results[] = (array)$document;
            }
            
            return $results;
        } catch (Exception $e) {
            echo("MongoDB Find Error: " . $e->getMessage());
            return [];
        }
    }

    public function findOne(string $collection, array $filter = []) {
        try {
            $document = $this->db->selectCollection($collection)->findOne($filter);
            return $document ? (array)$document : null;
        } catch (Exception $e) {
            echo("MongoDB FindOne Error: " . $e->getMessage());
            return null;
        }
    }

    public function update(string $collection, array $filter, array $update): array {
        try {
            $result = $this->db->selectCollection($collection)->updateMany(
                $filter,
                $update
            );
            return ['modifiedCount' => $result->getModifiedCount()];
        } catch (Exception $e) {
            echo("MongoDB Update Error: " . $e->getMessage());
            return ['error' => $e->getMessage()];
        }
    }

    public function delete(string $collection, array $filter): array {
        try {
            $result = $this->db->selectCollection($collection)->deleteMany($filter);
            return ['deletedCount' => $result->getDeletedCount()];
        } catch (Exception $e) {
            echo("MongoDB Delete Error: " . $e->getMessage());
            return ['error' => $e->getMessage()];
        }
    }
    
    /**
     * New method to iterate through large result sets efficiently
     * Returns a generator that yields documents one at a time
     */
    public function findIterate(string $collection, array $filter = [], array $options = []) {
        try {
            $cursor = $this->db->selectCollection($collection)->find($filter, $options);
            
            foreach ($cursor as $document) {
                yield (array)$document;
            }
        } catch (Exception $e) {
            echo("MongoDB Find Error: " . $e->getMessage());
            return;
        }
    }

    public function aggregate(string $collection, array $pipeline): array {
        try {
            $cursor = $this->db->selectCollection($collection)->aggregate($pipeline, [
                'typeMap' => ['root' => 'array', 'document' => 'array']
            ]);
            
            // Immediately convert cursor to array before any other operations
            $result = [];
            foreach ($cursor as $document) {
                $result[] = $document;
            }
            return $result;
            
            // Alternatively, if you're using mongodb/mongodb library:
            // return $cursor->toArray();
        } catch (Exception $e) {
            error_log("MongoDB Aggregate Error: " . $e->getMessage());
            return [];
        }
    }
}