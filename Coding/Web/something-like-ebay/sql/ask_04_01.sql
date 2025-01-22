INSERT INTO store( name , country ) VALUES ('elmepa' , 'greece'); 
INSERT INTO store( name , country ) VALUES ('amazon' , 'usa');

DELETE FROM store WHERE name='amazon'; 

INSERT INTO product(name, avail_amount , price, store_id ) VALUES ('shampoo',5,15,1);
INSERT INTO product(name, avail_amount , price, store_id ) VALUES ('screen',12,22,1);
INSERT INTO product(name, avail_amount , price, store_id ) VALUES ('mobile phone',12,22,1);

DELETE FROM product WHERE id=3;

INSERT INTO user (full_name,age,gender,date_of_sign) VALUES ('Nikitas Menounos',20,'male','2023-02-10'); 
INSERT INTO user (full_name,age,gender,date_of_sign) VALUES ('antonia',25,'female','2010-05-23'); 

DELETE FROM user WHERE full_name='antonia'; 

INSERT INTO order_ (date , cost , user_id) VALUES('2023-04-10',55,1);
INSERT INTO order_ (date , cost , user_id) VALUES('2023-05-15',102,1);

INSERT INTO order_prod (order_id , number, prod_id) VALUES(1, 2, 1);
INSERT INTO order_prod (order_id , number, prod_id) VALUES(2, 3, 2);

DELETE FROM order_prod WHERE prod_id=2;

UPDATE order_prod SET number= 5 WHERE prod_id= 1 ;

SELECT order_.date, order_.cost , order_prod.number , product.name
    FROM ((order_prod INNER JOIN order_ ON order_prod.order_id = order_.id) 
        INNER JOIN product ON order_prod.prod_id = product.id)
    WHERE order_.user_id = 1 ; 

SELECT * FROM product WHERE store_id = '1' ; 

SELECT * FROM product WHERE name LIKE 's%' ;
