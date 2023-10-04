import pandas as pd

def changeDatatype(students):
    return students.astype({'grade': int})
