import pandas as pd

def modifySalaryColumn(employees):
    employees['salary'] *= 2
    return employees
