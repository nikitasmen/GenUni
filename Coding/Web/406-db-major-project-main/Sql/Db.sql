-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Mar 29, 2025 at 11:34 AM
-- Server version: 8.0.39
-- PHP Version: 8.2.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `Forum`
--
CREATE DATABASE IF NOT EXISTS Forum;
USE Forum;
-- --------------------------------------------------------

--
-- Table structure for table `Comments`
--

CREATE TABLE `Comments` (
  `id` int NOT NULL,
  `text` varchar(30)  NOT NULL,
  `best` tinyint(1) NOT NULL,
  `postId` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `Posts`
--

CREATE TABLE `Posts` (
  `id` int NOT NULL,
  `text` varchar(60)  NOT NULL,
  `likes` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `Tech`
--

CREATE TABLE `Tech` (
  `id` int NOT NULL,
  `title` varchar(10)  NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `TechPost`
--

CREATE TABLE `TechPost` (
  `id` int NOT NULL,
  `postId` int NOT NULL,
  `techId` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE `User` (
  `userId` int NOT NULL,
  `firstName` varchar(15)  NOT NULL,
  `lastName` varchar(15)  NOT NULL,
  `countryOrigin` varchar(64) DEFAULT NULL,
  `phone` varchar(15) NOT NULL,
  `birthday` date DEFAULT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `UserAction`
--

CREATE TABLE `UserAction` (
  `id` int NOT NULL,
  `action` varchar(64)  NOT NULL,
  `date` timestamp(6) NOT NULL DEFAULT CURRENT_TIMESTAMP(6),
  `userId` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `UserAdmin`
--

CREATE TABLE `UserAdmin` (
  `id` int NOT NULL,
  `action` varchar(15) NOT NULL,
  `userId` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `UserExpert`
--

CREATE TABLE `UserExpert` (
  `id` int NOT NULL,
  `userId` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `UserFriends`
--

CREATE TABLE `UserFriends` (
  `id` int NOT NULL,
  `friendId` int NOT NULL,
  `userId` int NOT NULL
);

-- --------------------------------------------------------

--
-- Table structure for table `UserTech`
--

CREATE TABLE `UserTech` (
  `id` int NOT NULL,
  `userId` int NOT NULL,
  `techId` int NOT NULL,
  `rate` float NOT NULL
);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Comments`
--
ALTER TABLE `Comments`
  ADD PRIMARY KEY (`id`),
  ADD KEY `postId` (`postId`);

--
-- Indexes for table `Posts`
--
ALTER TABLE `Posts`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `Tech`
--
ALTER TABLE `Tech`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `TechPost`
--
ALTER TABLE `TechPost`
  ADD PRIMARY KEY (`id`),
  ADD KEY `postId` (`postId`),
  ADD KEY `techId` (`techId`);

--
-- Indexes for table `User`
--
ALTER TABLE `User`
  ADD PRIMARY KEY (`userId`);

--
-- Indexes for table `UserAction`
--
ALTER TABLE `UserAction`
  ADD PRIMARY KEY (`id`),
  ADD KEY `userId` (`userId`);

--
-- Indexes for table `UserAdmin`
--
ALTER TABLE `UserAdmin`
  ADD PRIMARY KEY (`id`),
  ADD KEY `userId` (`userId`);

--
-- Indexes for table `UserExpert`
--
ALTER TABLE `UserExpert`
  ADD PRIMARY KEY (`id`),
  ADD KEY `userId` (`userId`);

--
-- Indexes for table `UserFriends`
--
ALTER TABLE `UserFriends`
  ADD PRIMARY KEY (`id`),
  ADD KEY `friendId` (`friendId`),
  ADD KEY `userId` (`userId`);

--
-- Indexes for table `UserTech`
--
ALTER TABLE `UserTech`
  ADD PRIMARY KEY (`id`),
  ADD KEY `techId` (`techId`),
  ADD KEY `userId` (`userId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Comments`
--
ALTER TABLE `Comments`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Posts`
--
ALTER TABLE `Posts`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Tech`
--
ALTER TABLE `Tech`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `TechPost`
--
ALTER TABLE `TechPost`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `User`
--
ALTER TABLE `User`
  MODIFY `userId` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `UserAction`
--
ALTER TABLE `UserAction`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `UserAdmin`
--
ALTER TABLE `UserAdmin`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `UserExpert`
--
ALTER TABLE `UserExpert`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `UserFriends`
--
ALTER TABLE `UserFriends`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `UserTech`
--
ALTER TABLE `UserTech`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Comments`
--
ALTER TABLE `Comments`
  ADD CONSTRAINT `comments_ibfk_1` FOREIGN KEY (`postId`) REFERENCES `Posts` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Constraints for table `TechPost`
--
ALTER TABLE `TechPost`
  ADD CONSTRAINT `techpost_ibfk_1` FOREIGN KEY (`postId`) REFERENCES `Posts` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  ADD CONSTRAINT `techpost_ibfk_2` FOREIGN KEY (`techId`) REFERENCES `Tech` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Constraints for table `UserAction`
--
ALTER TABLE `UserAction`
  ADD CONSTRAINT `useraction_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Constraints for table `UserAdmin`
--
ALTER TABLE `UserAdmin`
  ADD CONSTRAINT `useradmin_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Constraints for table `UserExpert`
--
ALTER TABLE `UserExpert`
  ADD CONSTRAINT `userexpert_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Constraints for table `UserFriends`
--
ALTER TABLE `UserFriends`
  ADD CONSTRAINT `userfriends_ibfk_1` FOREIGN KEY (`friendId`) REFERENCES `User` (`userId`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  ADD CONSTRAINT `userfriends_ibfk_2` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE RESTRICT ON UPDATE RESTRICT;

--
-- Constraints for table `UserTech`
--
ALTER TABLE `UserTech`
  ADD CONSTRAINT `usertech_ibfk_1` FOREIGN KEY (`techId`) REFERENCES `Tech` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  ADD CONSTRAINT `usertech_ibfk_2` FOREIGN KEY (`userId`) REFERENCES `User` (`userId`) ON DELETE RESTRICT ON UPDATE RESTRICT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
