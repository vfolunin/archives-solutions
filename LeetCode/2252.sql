CREATE PROCEDURE PivotProducts()
BEGIN
	SET group_concat_max_len = 100000;

    SELECT GROUP_CONCAT(DISTINCT CONCAT("SUM(IF(store = '", store, "', price, null)) ", store) ORDER BY store)
    FROM Products
    INTO @columns;

    SET @sql = CONCAT("SELECT product_id, ", @columns, " FROM Products GROUP BY product_id");
    
    PREPARE query FROM @sql;
    EXECUTE query;
    DEALLOCATE PREPARE query;
END