import pandas as pd

def selectData(students):
    return students[students['student_id'] == 101][['name', 'age']]
