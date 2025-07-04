-- Enter new expert user 
INSERT INTO User (firstName, lastName, countryOrigin, phone, birthday) 
VALUES ('John', 'Doe', 'USA', '1234567890', '2000-12-05');

INSERT INTO UserExpert (userId) 
SELECT userId FROM User WHERE firstName = 'John' AND lastName = 'Doe';

-- Delete expert user 
DELETE FROM UserExpert 
WHERE userId = (SELECT userId FROM User WHERE firstName = 'John' AND lastName = 'Doe');

-- Create a new post 

INSERT INTO Posts (text, likes) VALUES 
('I love programming', '10');

-- Create a new comment for post 
INSERT INTO Comments (text, best, postId) VALUES 
('This is a comment','0', (SELECT id FROM Posts WHERE text = 'I love programming')); 

--  Delete comment and post 
DELETE FROM Comments WHERE text = 'This is a comment';
DELETE FROM Posts WHERE text = 'I love programming'; 
UPDATE Posts SET likes = likes -1  WHERE text = 'I love programming';

-- Add a new technology 
INSERT INTO Tech (title) VALUES ('JavaScript'); 
DELETE FROM Tech WHERE id = 1; 

-- Update Country of origin 
UPDATE User SET countryOrigin = 'USA' WHERE firstName = 'John' AND lastName = 'Doe';
UPDATE User SET countryOrigin = 'Sweden' WHERE firstName = 'John' AND lastName = 'Doe';

-- Update User expert text 
INSERT INTO Tech (title) VALUES ('PhP');

INSERT INTO User (firstName, lastName, countryOrigin, phone, birthday) 
VALUES ('Jane', 'Smith', 'USA', '0987654321', '1995-05-15');

INSERT INTO UserExpert (userId) 
SELECT userId FROM User WHERE firstName = 'Jane' AND lastName = 'Smith';

INSERT INTO UserTech (userId, techId, rate) 
SELECT u.userId, t.id, 10 
FROM User u, Tech t 
WHERE u.firstName = 'Jane' AND u.lastName = 'Smith' 
AND t.title = 'PhP';
