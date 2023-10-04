import pandas as pd

def meltTable(report):
    return report.melt(id_vars='product', var_name='quarter', value_name='sales')
