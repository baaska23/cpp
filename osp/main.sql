--database
create database myBase
use myBase
--table and insert
create table Table1(
    tableID int,
    numID int,
    customerName varchar(50),
)
insert into Table1(tableID, numID, customerName)
values(
    (23, 123, 'Clay'),
    (67, 314, 'Heissenberg')
)

--cte
with Supp as(
    select * from Customer
    where id = '12'
)
select * from User u
inner join Supp s on s.id = u.id

--function
create function sumPrice(@OrderID int, ProductID, int)
returns table
as 
return
select * from Products p join Order o on p.id = o.id
where orderId = @OrderID and productID = @ProductID
select * from sumPrice(12312, 34)

--view
create view Employee as
select top 10 fName, Age from Emp

--procedure
create proc totalSales (@startDate date, @endDate date) as
begin
select sum(s.num) as total from Sales s
where s.start = @startDate and s.end = @endDate
end
exec totalSales @startDate = '2000-09-19', @endDate = '2023-08-12'
drop proc totalSales

--declare
declare @declaredVar int = 23
declare @employeeName varchar(20) = 'Kai Uuganbadrakh'
declare @currentDate = GETDATE();
declare @bookID int
set @bookID = 23213

declare @massive table(
    id int,
    name varchar(40),
)
insert into @massive
values(12, 'hey')

--concat
select * from Customer
where fullName = concat(fname, '', lname);

create function totalSalesByCountry(@countryName varchar(20))
returns table
as
return



--Uliral

-- 1.
--create view Employees_view as
select EmployeeID, concat(FirstName,' ' ,LastName) as Name, Title, City, Extension
from Employees where city='London';

-- 2. create view Salesperson as
select EmployeeID as salesman_ID, concat(FirstName,' ' ,LastName) as Name, City
from Employees;

-- 3. create view City as
select City, count(City)as NumberOfCustumors
from Customers
group by City;

--4
select o.OrderDate, count(o.OrderDate)as NumberOfCustumors, avg(od.UnitPrice) as avgSales, sum(od.UnitPrice) as TotalSales
from Orders o, [Order Details] od
where o.OrderID=od.OrderID
group by OrderDate;

-- 5. create view Salesperson/Customer as
select o.OrderID as ord_no, od.UnitPrice as purch_amt, e.EmployeeID as salesman_id, concat(FirstName,' ' ,LastName) as Emp_name, c.ContactName Cust_name
from orders o, Employees e, Customers c, [Order Details] od
where c.CustomerID=o.CustomerID and e.EmployeeID=o.EmployeeID and o.OrderID=od.OrderID;

-- 6. create view maximumAmountOrder as
select o.OrderDate, o.OrderID, e.EmployeeID, UnitPrice * Quantity as Amount
from Employees e
join Orders o on e.EmployeeID = o.EmployeeID
join [Order Details] od on o.OrderID = od.OrderID
where UnitPrice * Quantity = (select max(UnitPrice * Quantity)
from Orders s
join [Order Details] os on s.OrderID = os.OrderID
where s.OrderDate = o.OrderDate);



-- 7. create view maximumAmountOrder2 as
select o.OrderDate, e.EmployeeID, UnitPrice * Quantity as purch_amt
from Employees e
join Orders o on e.EmployeeID = o.EmployeeID
join [Order Details] od on o.OrderID = od.OrderID
where UnitPrice * Quantity = (select max(UnitPrice * Quantity)
from Orders s
join [Order Details] os on s.OrderID = os.OrderID
where s.OrderDate = o.OrderDate);

-- 8.
select top 10 c.CustomerID, ContactName as cust_name, c.city, count(o.CustomerID) as TotalOrders
from Customers c, Orders o
where c.CustomerID=o.CustomerID
group by c.CustomerID, c.ContactName, c.City
order by TotalOrders desc;

-- 9.
select City, count(City)as NumberOfSalesperson
from Employees
group by City;

-- 10.
select concat(FirstName,' ' ,LastName) as Name,
(select avg(UnitPrice) from [Order Details] od where o.OrderID=od.OrderID)as avg,
(select sum(UnitPrice) from [Order Details] od where o.OrderID=od.OrderID) as sum
from Orders o, Employees e
where o.EmployeeID=e.EmployeeID;

-- 11.
select e.EmployeeID, concat(e.FirstName, ' ', e.LastName) as Name, e.City,count(c.CustomerID) as CustomerCount
from Employees e, Orders o, Customers c
where e.EmployeeID = o.EmployeeID and o.CustomerID = c.CustomerID
group by e.EmployeeID, concat(e.FirstName, ' ', e.LastName), e.City
having count(c.CustomerID) > 1;

-- 12.
select c.City as Cust_city, e.City as Employee_city
from Employees e, Customers c
where e.City=c.City
group by e.City, c.City;

-- 13.
select OrderDate, count(orderDate) as NumberOfOrders
from Orders
group by OrderDate;
-- 14.
-- create view Transaction as
select e.EmployeeID as salesman_id, concat(FirstName,' ' ,LastName), City, Freight as commission
from Employees e, Orders o
where e.EmployeeID=o.EmployeeID and OrderDate between '1996-10-01' and '1996-10-31';

-- 15. create view Transaction97_98 as
select e.EmployeeID as salesman_id, count(orderid) as total_ord_num
from Employees e, Orders o
where e.EmployeeID=o.EmployeeID and OrderDate between '1997-01-01' and '1998-12-31'
group by e.EmployeeID;




Paper View
1. CREATE  VIEW book AS
SELECT t.title,  t.title_id, t.[type], t.price, a.au_lname, a.au_fname, a.phone, a.zip, s.ord_date, s.qty, e.fname, e.lname, p.pub_name,
p.city as publisher_city, p.[state] as publisher_state, p.country as publisher_country, st.stor_name as store_name,  st.stor_address as store_address, st.city as store_city,
st.[state] as store_state, st.zip as store_zip FROM dbo.titles t
JOIN dbo.titleauthor ta ON t.title_id = ta.title_id
JOIN dbo.authors a ON ta.au_id = a.au_id
JOIN dbo.sales s ON s.title_id = t.title_id
JOIN dbo.publishers p ON t.pub_id = p.pub_id
JOIN dbo.employee e ON p.pub_id = e.pub_id
JOIN dbo.stores st ON s.stor_id = st.stor_id
SELECT* FROM book
 

2. 1992 онд хамгийн их тоогоор зарагдсан 10 номыг
Book Title, Book Type, Book Price, Author Name.
(First letter of Author’s Last Name), Order Date,
Order Quantity талбарууд харуулах “Best Sellers”
нэртэй харагдац бичиж үр дүнг харуулаарай. (Өмнөх харагдацыг ашиглана)
 

CREATE VIEW BestSellers AS
SELECT TOP 10
b.title AS Book_Title,
b.[type] AS Book_Type,
b.price AS Book_Price,
CONCAT(LEFT(b.au_lname, 1), '.') AS Author_Initial,
b.ord_date AS Order_Date,
SUM(b.qty) AS Order_Quantity
FROM book b
WHERE YEAR(b.ord_date) = 1992
GROUP BY b.title, b.[type], b.price, b.au_lname, b.ord_date
ORDER BY SUM(b.qty) DESC;
SELECT *FROM BestSellers
 

3. Захиалгын дугаар(OrderID) болон Барааны дугаар(ProductId)
өгөгдөхөд тухайн захиалга дахь бараа тус бүрийн үнийн
дүнг тооцоолох скаляр хэрэглэгчийн функц бичээрэй.
Үнийн дүн = (Unitprice – Unitprice*Discount)* Quantity
CREATE FUNCTION SumPrice (@OrderID int, @ProductID int)
RETURNS table
AS
RETURN
SELECT p.ProductID, p.UnitPrice -p.UnitPrice*p.Discontinued as Price
FROM dbo.Products p
INNER JOIN dbo.[Order Details] od ON od.ProductID = p.ProductID
INNER JOIN dbo.Orders o ON od.OrderID = o.OrderID
WHERE o.OrderID = @OrderID AND p.ProductID = @ProductID
SELECT * FROM dbo.SumPrice(10248, 72)
 

4. Өгөгдсөн жилд хийгдсэн нийт борлуулалтын дүнг
харуулах хэрэглэгчийн функц бичээрэй. Жишээлбэл:
1998 хийгдсэн бүх захиалгын дүнг харуулах.
 

CREATE FUNCTION YearOrderPrice (@Year datetime)
RETURNS table
AS
RETURN
SELECT o.OrderID, od.UnitPrice -od.UnitPrice*od.Discount AS Price
FROM dbo.[Order Details] od
INNER JOIN dbo.Orders o ON od.OrderID = o.OrderID
WHERE YEAR(o.OrderDate) = YEAR(@Year)
SELECT sum(y.Price) AS TotalPriceInYear FROM YearOrderPrice('1998') 
 

5. Ямар нэгэн он өгөгдөхөд тухайн оны сар бүрд
хийгдсэн нийт гүйлгээний тоог саруудын хамт
харуулах хэрэглэгчийн функц бичээрэй.
CREATE FUNCTION YearOrderPrice (@Year datetime)
RETURNS TABLE
AS
RETURN
SELECT year(o.OrderDate) AS year, MONTH(o.OrderDate) AS Month, count(*) AS total
FROM dbo.[Order Details] od
JOIN dbo.Orders o ON o.OrderID = od.OrderID
JOIN dbo.Employees e ON e.EmployeeID = o.EmployeeID
WHERE YEAR(o.OrderDate) like YEAR(@Year)
GROUP BY MONTH(o.OrderDate), YEAR(o.OrderDate)
SELECT * FROM YearOrderPrice('1997')
 

6. Өгөгдсөн хугацаанд(Start date, End Date) хийгдсэн нийт
борлуулалтын дүн(Total Sale) харуулах хэрэглэгчийн функц бичээрэй
CREATE FUNCTION StartEndTotalSale (@Start datetime, @End datetime)
RETURNS table
AS
RETURN
SELECT SUM(pod.UnitPrice) as TotalSale, pod.DueDate from Purchasing.PurchaseOrderDetail pod
WHERE pod.DueDate >= @Start AND pod.DueDate <= @End
GROUP BY pod.DueDate
SELECT * from StartEndTotalSale('2011-04-30', '2012-06-01')
SELECT SUM(TotalSale) AS TotalPrice FROM StartEndTotalSale('2011-04-30', '2012-06-01')
 

7. Өгөгдсөн хугацаанд (Start date, End Date) хийгдсэн нийт захиалгын
тоо (Total Invoice) харуулах хэрэглэгчийн функц бичээрэй
CREATE FUNCTION StartEndTotalInvoice (@Start datetime, @End datetime)
RETURNS int
AS
BEGIN
DECLARE @num_orders int
SELECT @num_orders = count(soh.SalesOrderID) FROM Sales.SalesOrderHeader soh
WHERE soh.OrderDate >= @Start AND soh.OrderDate <= @End
RETURN @num_orders
END
SELECT dbo.StartEndTotalInvoice('2011-05-31', '2011-05-31')
 

8. Өгөгдсөн хугацаанд (Start date, End Date) хийгдсэн өдөр тутмын
борлуулалтын дунджийг (Avg Daily Sales) харуулах хэрэглэгчийн функц бичээрэй
CREATE FUNCTION StartEndAvgTotal (@Start datetime, @End datetime)
RETURNS table
AS
RETURN
SELECT avg(pod.UnitPrice) AS AvgDailySales, pod.DueDate FROM Purchasing.PurchaseOrderDetail pod
WHERE pod.DueDate >= @Start AND pod.DueDate <= @End
GROUP BY pod.DueDate
SELECT * FROM StartEndAvgTotal('2011-04-30', '2012-06-01')
 

9. Бараа материалын төрлүүд болон тухайн төрөл тус бүрд байгаа
бараа бүтээгдэхүүний тоог хүснэгтэн утгат функцээр харуулаарай
CREATE FUNCTION ProductTypeInCount()
RETURNS TABLE
AS
return
SELECT pc.ProductCategoryID, psc.ProductSubcategoryID, count(ProductID) AS ProductCount FROM Production.ProductCategory pc
JOIN Production.ProductSubcategory psc ON pc.ProductCategoryID = psc.ProductCategoryID
JOIN Production.Product p ON p.ProductSubcategoryID = psc.ProductSubcategoryID
GROUP BY psc.ProductSubcategoryID, pc.ProductCategoryID
SELECT * FROM ProductTypeInCount();
 

10. Өгөгдсөн хугацаанд хамгийн их борлуулалттай 5 бүтээгдэхүүнийг
#TOP5 нэртэй түр хүснэгт (temporary) хүснэгтэд хийж үр дүнг харуулаарай
CREATE TABLE #TOP5 (
ProductID int IDENTITY(1,1) PRIMARY KEY,
ProductName varchar(50)
)
INSERT INTO #TOP5(ProductName)
SELECT TOP 3 p.[Name]
FROM Purchasing.PurchaseOrderDetail pod
JOIN Production.Product p ON pod.ProductID = p.ProductID
WHERE pod.DueDate >= '2011-04-30' AND pod.DueDate <= '2012-06-01'
GROUP BY p.ProductID, p.[Name]
ORDER BY COUNT(*) DESC;
SELECT * FROM #TOP5;




Paper View
1.

SELECT a.SupplierID, a.ProductName, a.CategoryName,
(SELECT CompanyName
FROM [Northwind].[dbo].[Suppliers] s
WHERE s.SupplierID = a.SupplierID) AS CompanyName FROM [Northwind].[dbo].[Alphabetical list of products] a
WHERE a.SupplierID = (
SELECT SupplierID FROM [Northwind].[dbo].[Suppliers]
WHERE CompanyName = 'Specialty Biscuits, Ltd.'
);
2.
WITH Supp AS (
SELECT SupplierID, CompanyName FROM [Northwind].[dbo].[Suppliers]
WHERE CompanyName = 'Specialty Biscuits, Ltd.'
)
SELECT a.SupplierID, a.ProductName, a.CategoryName, s.CompanyName FROM [Northwind].[dbo].[Alphabetical list of products] a
INNER JOIN Supp s ON a.SupplierID = s.SupplierID;
3.
SELECT e.FirstName, e.LastName, e.JobTitle, p.Rate,
(SELECT MIN(p2.Rate) FROM [AdventureWorks2012].[HumanResources].[vEmployee] e2
JOIN [AdventureWorks2012].[HumanResources].[EmployeePayHistory] p2 ON p2.BusinessEntityID = e2.BusinessEntityID
WHERE e2.JobTitle LIKE '%Engineer%') AS MinRate,
(SELECT MAX(p3.Rate) FROM [AdventureWorks2012].[HumanResources].[vEmployee] e3
JOIN [AdventureWorks2012].[HumanResources].[EmployeePayHistory] p3 ON p3.BusinessEntityID = e3.BusinessEntityID
WHERE e3.JobTitle LIKE '%Engineer%') AS MaxRate,
(SELECT AVG(p4.Rate) FROM [AdventureWorks2012].[HumanResources].[vEmployee] e4
JOIN [AdventureWorks2012].[HumanResources].[EmployeePayHistory] p4 ON p4.BusinessEntityID = e4.BusinessEntityID
WHERE e4.JobTitle LIKE '%Engineer%') AS AvgRate FROM [AdventureWorks2012].[HumanResources].[vEmployee] e
JOIN [AdventureWorks2012].[HumanResources].[EmployeePayHistory] p ON p.BusinessEntityID = e.BusinessEntityID
WHERE e.JobTitle LIKE '%Engineer%'
ORDER BY p.Rate DESC;
4.
WITH Emp AS (
SELECT e.FirstName, e.LastName, e.JobTitle, p.Rate FROM [AdventureWorks2012].[HumanResources].[vEmployee] e
JOIN [AdventureWorks2012].[HumanResources].[EmployeePayHistory] p ON p.BusinessEntityID = e.BusinessEntityID
WHERE e.JobTitle LIKE '%Engineer%'
ORDER BY p.Rate DESC
)
SELECT *,
(SELECT MIN(Rate) FROM Emp) AS MinRate,
(SELECT MAX(Rate) FROM Emp) AS MaxRate,
(SELECT AVG(Rate) FROM Emp) AS AvgRate FROM Emp;
5.
SELECT FirstName, LastName,StateProvinceName AS Name,'US' AS CountryRegionCode FROM [AdventureWorks2012].[HumanResources].[vEmployee]
WHERE CountryRegionName = 'United States'

UNION ALL

SELECT FirstName, LastName,StateProvinceName AS Name, 'CA' AS CountryRegionCode
FROM [AdventureWorks2012].[HumanResources].[vEmployee]
WHERE CountryRegionName = 'Canada'
ORDER BY Name ASC;
6.
WITH Country AS (
SELECT FirstName, LastName, StateProvinceName AS Name,'US' AS CountryRegionCode
FROM [AdventureWorks2012].[HumanResources].[vEmployee]
WHERE CountryRegionName = 'United States'
UNION ALL
SELECT FirstName, LastName, StateProvinceName AS Name,'CA' AS CountryRegionCode
FROM [AdventureWorks2012].[HumanResources].[vEmployee]
WHERE CountryRegionName = 'Canada'
)
SELECT FirstName, LastName, Name, CountryRegionCode FROM Country
ORDER BY Name ASC;
7.
SELECT st.TerritoryID,
MIN(sp.SalesYTD) AS MinYTD,
MAX(sp.SalesYTD) AS MaxYTD,
AVG(sp.SalesYTD) AS AvgYTD FROM [AdventureWorks2012].[Sales].[SalesPerson] sp
INNER JOIN [AdventureWorks2012].[Sales].[SalesTerritory] st ON sp.TerritoryID = st.TerritoryID
GROUP BY st.TerritoryID;
8.
WITH Sales AS (
SELECT st.TerritoryID,
MIN(sp.SalesYTD) AS MinYTD,
MAX(sp.SalesYTD) AS MaxYTD,
AVG(sp.SalesYTD) AS AvgYTD FROM [AdventureWorks2012].[Sales].[SalesPerson] sp
INNER JOIN [AdventureWorks2012].[Sales].[SalesTerritory] st ON sp.TerritoryID = st.TerritoryID
GROUP BY st.TerritoryID
)
SELECT TerritoryID, MinYTD, MaxYTD, AvgYTD FROM Sales;
9.
WITH AvgYTD AS (
SELECT TerritoryID,
MIN(SalesYTD) AS MinYTD,
AVG(SalesYTD) AS AvgYTD,
MAX(SalesYTD) AS MaxYTD FROM [AdventureWorks2012].[Sales].[SalesPerson]
GROUP BY TerritoryID
)
SELECT sp.BusinessEntityID AS SalesPersonID, sp.SalesYTD, sp.TerritoryID,ty.MinYTD AS MinYTDForTerritory
FROM [AdventureWorks2012].[Sales].[SalesPerson] sp
JOIN AvgYTD ty ON sp.TerritoryID = ty.TerritoryID
WHERE sp.SalesYTD > ty.MinYTD;
10.
SELECT t.ProductID FROM [AdventureWorks2012].[Production].[TransactionHistory] t
LEFT JOIN [AdventureWorks2012].[Production].[TransactionHistoryArchive] ta ON t.ProductID = ta.ProductID
WHERE ta.ProductID != t.ProductID
ORDER BY t.ProductID;
--may second solution work if not first
SELECT t.ProductID FROM [AdventureWorks2012].[Production].[TransactionHistory] t
where t.ProductID not in (SELECT ta.ProductID FROM [AdventureWorks2012].[Production].[TransactionHistoryArchive] ta);



