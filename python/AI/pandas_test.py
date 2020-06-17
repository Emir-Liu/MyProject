import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("titanic.csv",header=0)

print(df.head())

print(df.describe())

df["age"].plot.hist()

plt.show()
