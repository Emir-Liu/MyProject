import urllib2
page = urllib2.urlopen("https://emir-liu.github.io")
html = page.read()
print(html)
