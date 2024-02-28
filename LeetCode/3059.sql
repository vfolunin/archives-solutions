SELECT SUBSTR(email, LOCATE("@", email) + 1) email_domain, COUNT(DISTINCT id) count
FROM Emails
WHERE email LIKE "%.com"
GROUP BY email_domain;