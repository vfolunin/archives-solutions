import pandas as pd

def fillMissingValues(products):
    products['quantity'].fillna(0, inplace=True)
    return products
