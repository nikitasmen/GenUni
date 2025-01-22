SELECT SUM(cost) FROM order_ WHERE user_id = 1 ;

SELECT SUM(order_.cost) 
	FROM (((order_prod INNER JOIN order_ ON order_prod.order_id = order_.id)
    	INNER JOIN product ON product.id = order_prod.prod_id) 
  		INNER JOIN store ON product.store_id = store.id)
	WHERE store.id = 1 ;

SELECT name,SUM(number),SUM(order_prod.number * product.price)  
	FROM (product INNER JOIN order_prod  ON product.id = order_prod.prod_id) 
    	GROUP BY name 
			ORDER BY sum(order_prod.number * product.price) DESC 
            LIMIT 3;

SELECT categories.name , COUNT(*) AS likes 
	FROM user_cat INNER JOIN categories ON categories.id = user_cat.cat_id
    	GROUP BY categories.id 
        ORDER BY likes DESC 
        LIMIT 3 ;
          

SELECT categories.name , COUNT(*) AS likes 
	FROM product_cat INNER JOIN categories ON categories.id = product_cat.cat_id
    	GROUP BY categories.id 
        ORDER BY likes DESC 
        LIMIT 3 ;        