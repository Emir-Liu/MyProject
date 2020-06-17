import urllib.request

url = "https://raw.githubusercontent.com/Emir-Liu/practicalAI/master/data/titanic.csv"

response = urllib.request.urlopen(url)
html = response.read()

with open('titanic.csv','wb') as f:
    f.write(html)

