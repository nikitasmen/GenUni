<?php
require('../db/connection.php');
require('../models/Books.php');
require('./Categories.php');
class Books {
    private $db;
    private $book;
    private $category; 
    public function __construct() {
        // Initialize the database connection and the Book model
        $this->db = new Database();
        $this->book = new Book($this->db->getConnection());
        $this->category = new Categories(); 
        // Enable CORS
        header("Access-Control-Allow-Origin: http://localhost:8080"); // Allow only your frontend origin
        header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
        header("Access-Control-Allow-Headers: Content-Type, Authentication, Authorization");
        
        
    }
    public function handleRequest() {
        
        // Handle preflight requests
        // if ($_SERVER['REQUEST_METHOD'] == 'OPTIONS') {
        //     http_response_code(200);
        //     exit();
        // }
        //Enable CORS for all origins 
      
        // Get the request method and endpoint
        $method = $_SERVER['REQUEST_METHOD'];
        $endpoint = $_GET['api'] ?? '';
        // echo $endpoint; // addBook 
        // Route the request to the appropriate method
        switch ($endpoint) {
            case 'addBook':
                $this->addBook($method);
                break;
            case 'getAllBooks':
                $this->getAllBooks($method);
                break;
            case 'searchBooks':
                $this->searchBooks($method);
                break;
            case 'getBookDetails': 
                $this->getBookDetails($method);
                break;
            case 'getCategories':
                $this->getCategories($method);
                break;
            default:
                $this->respond(404, ['error' => 'Endpoint not found']);
        }
    }
    private function addBook($method) {
        if ($method != 'POST') {
            $this->respond(405, ['error' => 'Method not allowed']);
            return;
        }
    
        $data = json_decode(file_get_contents('php://input'), true);
       
        if (!$data) {
            $this->respond(400, ['error' => 'Invalid input data']);
            return;
        }
    
        $title = $data['title'];
        $author = $data['author']; 
        $description = $data['description'];
        $year = $data['year'];
        $copies = $data['copies'];
        $condition = $data['condition'];

        try{
            $bookId = $this->book->addBook($title, $author, $year, $condition, $copies, $description);
            if (!$bookId['status']) {
                $this->respond(500, ['message' => 'Error adding book', 'error' => $bookId]);
                return;
            }
            $response = $this->category->addCategories();
            if ($response['status']) {
                $this->respond(200, ['message' => 'Book added successfully', 'data' => $response]);
                return;
            }
        }catch (\Exception $e){
            $this->respond(500, ['message' => 'Error adding book category', 'error'=> $e->getMessage()]);
            return;
        }
    }
    private function getAllBooks($method) {
        if ($method !== 'GET') {
            $this->respond(405, ['error' => 'Method not allowed']);
            return;
        }

        $books = $this->book->getAllBooks();
        $this->respond(200, $books);
    }

    private function getBookDetails($method) {
        if ($method !== 'GET') {
            $this->respond(405, ['error' => 'Method not allowed']);
            return;
        }

        $bookId = $_GET['bookId'];
        if(!$bookId) {
            $this->respond(400, ['error' => 'Invalid input data']);
            return;
        }
        
        $book = $this->book->getBookDetails($bookId);
        $this->respond(200, $book);
    }

    private function searchBooks($method) {
        if ($method !== 'GET') {
            $this->respond(405, ['error' => 'Method not allowed']);
            return;
        }

        $title = $_GET['title'];
        if(!$title) {
            $this->respond(400, ['error' => 'Invalid input data']);
            return;
        }
        
        $books = $this->book->searchBooks($title);
        $this->respond(200, $books);
        return; 
    }

    private function respond($statusCode, $data) {
        http_response_code($statusCode);
        header('Content-Type: application/json');
        echo json_encode($data);
    }

    private function getCategories($method){
        if ($method !== 'GET') {
            $this->respond(405, ['error' => 'Method not allowed']);
            return;
        }

        $bookId = $_GET['bookId'];
        if(!$bookId) {
            $this->respond(400, ['error' => 'Invalid input data']);
            return;
        }
        $categories = $this->category->getBookCategories($bookId);
        $this->respond(200, $categories);
        return; 

    }
    private function getBookId($bookId) {
        
    }
}

// Handle the API request
$api = new Books();
$api->handleRequest();
