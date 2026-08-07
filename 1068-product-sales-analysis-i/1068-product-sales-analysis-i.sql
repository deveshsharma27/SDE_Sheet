# Write your MySQL query statement below
select product_name , year , price from Sales
inner join Product 
On Product.product_id = Sales.product_id