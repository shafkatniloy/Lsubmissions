SELECT x.customer_id
FROM (
    SELECT customer_id, COUNT(DISTINCT product_key) AS total_product
    FROM Customer
    GROUP BY customer_id
) x
WHERE x.total_product = (SELECT COUNT(*) FROM Product);