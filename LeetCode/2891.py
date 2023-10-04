import pandas as pd

def findHeavyAnimals(animals):
    return animals[animals['weight'] > 100].sort_values(by='weight', ascending=False)[['name']]
