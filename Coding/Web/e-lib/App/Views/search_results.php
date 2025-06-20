<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Results</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css" rel="stylesheet">
    <link rel="stylesheet" href="/styles/searchResults.css"> 
</head>
<body class="d-flex flex-column min-vh-100">

    <?php 
        include 'Partials/Header.php'; 
        include 'Components/SearchForm.php';
    ?>
    <div class="container mt-5">
        <div class="row mb-4">
            <div class="col">
                <h2>Search Results <?= !empty($searchQuery) ? 'for "' . htmlspecialchars($searchQuery) . '"' : '' ?></h2>
            </div>
        </div>
        
        <!-- Display results in a grid -->
        <div class="row">
            <?php if (!empty($results)): ?>
                <?php foreach ($results as $book): ?>
                    <?php include 'Components/BookCard.php'; ?>
                <?php endforeach; ?>
            <?php else: ?>
                <div class="col-12">
                    <div class="alert alert-info">
                        No results found for "<?= htmlspecialchars($searchQuery) ?>".
                    </div>
                </div>
            <?php endif; ?>
        </div>
    </div>
    <?php 
        include 'Partials/Footer.php';
    ?>
       

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>
</html>