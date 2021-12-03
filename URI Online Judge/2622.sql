SELECT customers.name
FROM legal_person
JOIN customers ON legal_person.id_customers = customers.id;