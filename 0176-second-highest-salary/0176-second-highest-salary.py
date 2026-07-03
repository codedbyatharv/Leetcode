import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    s = employee["salary"].drop_duplicates().nlargest(2)

    return pd.DataFrame({
        "SecondHighestSalary": [s.iloc[-1] if len(s) == 2 else None]
    })
    