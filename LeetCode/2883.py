import pandas as pd

def dropMissingData(students):
    return students.dropna(subset='name')
