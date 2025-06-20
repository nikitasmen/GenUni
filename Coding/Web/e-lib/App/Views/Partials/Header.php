<?php
/**
 * Navbar Component
 * 
 * @param string $activePage Optional - current active page for nav highlight
 * @param string $searchUrl Optional - search form submission URL (default: '/search_results')
 */

// Default values
$activePage = $activePage ?? '';
$searchUrl = $searchUrl ?? '/search_results';
?>
<link rel="stylesheet" href="/styles/userForm.css">
<nav class="navbar navbar-expand-lg navbar-dark bg-dark shadow-sm">
    <div class="container">
        <a class="navbar-brand fw-bold" href="/">
            <i class="fas fa-book-open me-2"></i>Epictetus Library
        </a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav me-auto">
                <li class="nav-item">
                    <a class="nav-link <?= $activePage === 'home' ? 'active' : '' ?>" href="/">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link <?= $activePage === 'books' ? 'active' : '' ?>" href="/view-books">Books</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link <?= $activePage === 'add' ? 'active' : '' ?>" href="/add-book">Add Book</a>
                </li>
            </ul>

            <form class="d-flex me-3" id="searchForm" action="<?= htmlspecialchars($searchUrl) ?>" method="GET">
                <div class="input-group">
                    <input type="search" name="title" id="bookToSearch" class="form-control" 
                           placeholder="Search titles..." aria-label="Search">
                    <button type="submit" class="btn btn-success">
                        <i class="fas fa-search"></i>
                    </button>
                </div>
            </form>

            <?php if (!empty($_SESSION['user_id'])): ?>
                <!-- User is logged in -->
                <div id="profileDropdown" class="dropdown" style="display: none;">
                    <button class="btn btn-outline-light dropdown-toggle d-flex align-items-center" type="button" id="userDropdown" data-bs-toggle="dropdown" aria-expanded="false">
                        <div class="user-avatar me-2"><?= substr($username, 0, 1) ?></div>
                        <span class="d-none d-md-inline"><?= htmlspecialchars($username) ?></span>
                    </button>
                    <ul class="dropdown-menu dropdown-menu-end" aria-labelledby="userDropdown">
                        <li><a class="dropdown-item" href="/profile"><i class="fas fa-user me-2"></i>Profile</a></li>
                        <li><a class="dropdown-item" href="/book"><i class="fas fa-bookmark me-2"></i>My Books</a></li>
                        <li><hr class="dropdown-divider"></li>
                        <li>
                            <a class="dropdown-item" href="#" onclick="handleLogout(event)">
                                <i class="fas fa-sign-out-alt me-2"></i>Logout
                            </a>
                        </li>
                    </ul>
                </div>
            <?php else: ?>
                <!-- User is not logged in -->
                <div class="d-flex">
                    <button id="userAction" class="btn btn-outline-light me-2" onclick="openPopup('loginPopup')">Login</button>
                    <button id="userAction" class="btn btn-primary" onclick="openPopup('signupPopup')">Sign Up</button>
                </div>
            <?php endif; ?>
        </div>
    </div>
</nav>

<!-- Login Popup -->
<div id="loginPopup" class="popup-overlay" style="display:none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; 
                background-color: rgba(0,0,0,0.5); z-index: 1050;">
        <?php include __DIR__ . '/../Components/LoginForm.php'; ?>
</div>

<!-- Signup Popup -->
<div id="signupPopup" class="popup-overlay" style="display:none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; 
                background-color: rgba(0,0,0,0.5); z-index: 1050;">
        <?php include __DIR__ . '/../Components/SignUpForm.php'; ?>
</div>


<script src="https://cdn.jsdelivr.net/npm/axios/dist/axios.min.js"></script>
<script>
function handleLogout(event) {
    event.preventDefault();
    axios.get('/api/v1/logout')
        .then(response => {
            if (response.data.status === 'success') {
                if (localStorage.getItem('authToken')) {
                    localStorage.removeItem('authToken');
                }
                if (sessionStorage.getItem('authToken')) {
                    sessionStorage.removeItem('authToken');
                }
                window.location.href = '/';
            }
        })
        .catch(error => {
            console.error('Logout error:', error);
        });
}
function closePopup(popupId) {
    const popup = document.getElementById(popupId);
    if (popup) {
        popup.style.display = 'none';
    } else {
        console.error(`Popup with id "${popupId}" not found.`);
    }
}

function openPopup(popupId) {
    const popup = document.getElementById(popupId);
    if (!popup) {
        console.error(`Popup with id "${popupId}" not found.`);
        return;
    }
    popup.style.display = 'flex';
    console.log(`Popup dimensions: width=${popup.offsetWidth}, height=${popup.offsetHeight}`);
}
document.addEventListener('DOMContentLoaded', function () {
    const authToken = localStorage.getItem('authToken') || sessionStorage.getItem('authToken');
    const loginButtons = document.querySelectorAll('#userAction');
    const userDropdown = document.querySelector('#profileDropdown');
    const urlParams = new URLSearchParams(window.location.search);
    
    if (urlParams.has('showLogin') || window.location.pathname === '/login') {
        openPopup('loginPopup');
    } else if (urlParams.has('showSignup') || window.location.pathname === '/signup') {
        openPopup('signupPopup');
    }

    if (authToken) {
        // User is logged in
        if (loginButtons) {
            loginButtons.forEach(button => button.style.display = 'none');
        }
        console.log('User is logged in');
        if (userDropdown) {
            userDropdown.style.display = 'block';
        }
    } else {
        // User is not logged in
        if (loginButtons) {
            loginButtons.forEach(button => button.style.display = 'block');
        }
        if (userDropdown) {
            userDropdown.style.display = 'none';
        }
    }
});
</script>
