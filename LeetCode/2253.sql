CREATE PROCEDURE UnpivotProducts()
BEGIN
	SET group_concat_max_len = 100000;

    SELECT GROUP_CONCAT(
        CONCAT("SELECT product_id, '", column_name, "' store, ", column_name, " price FROM products WHERE ", column_name, " IS NOT NULL")
        SEPARATOR " UNION ALL "
    )
    FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = "Products" AND COLUMN_NAME <> "product_id"
    INTO @sql;
    
    PREPARE query FROM @sql;
    EXECUTE query;
    DEALLOCATE PREPARE query;
END