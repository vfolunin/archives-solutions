import pandas as pd

def dropDuplicateEmails(customers):
    return customers.drop_duplicates(subset='email')
