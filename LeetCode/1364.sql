WITH ContactCount AS (
    SELECT user_id, COUNT(DISTINCT contact_name) contacts_cnt
    FROM Contacts
    GROUP BY user_id
), TrustedContactCount AS (
    SELECT user_id, COUNT(DISTINCT contact_name) trusted_contacts_cnt
    FROM Contacts JOIN Customers ON contact_name = customer_name
    GROUP BY user_id
)
SELECT invoice_id, customer_name, price, IFNULL(contacts_cnt, 0) contacts_cnt, IFNULL(trusted_contacts_cnt, 0) trusted_contacts_cnt
FROM Invoices JOIN Customers ON user_id = customer_id LEFT JOIN ContactCount USING(user_id) LEFT JOIN TrustedContactCount USING(user_id)
ORDER BY invoice_id