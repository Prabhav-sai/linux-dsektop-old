# %%
import re
from nltk.corpus import stopwords
from collections import defaultdict
from nltk.stem import SnowballStemmer
from nltk.stem import WordNetLemmatizer

# %%
filename = "census1931.txt"
infile = open(filename,'r')
text = infile.read()
infile.close()

# %%
print(text[:100])

# %%
#Tokenise

unrefinedStr = re.sub(r'\—|\'|\`|\"|\||\.|\*|\[|\{|\}|\(|\)|\]|\;|\:|\,|\^|\=|\-|\+|\_|\!|\?|\/|\>|\<|\&|\\|\#|\n', r' ', text) # removing special characters

# %%
print(unrefinedStr)

# %%
tokens = unrefinedStr.split()

# %%
print(len(tokens))
print(tokens[:20])#print(tokens[0:20:1])

# %%
tokens = [myword.lower() for myword in tokens]


# %%
print(tokens[:20])

# %%
import nltk
nltk.download('stopwords')

# %%
mystopwords = set(stopwords.words("english"))
print(len(mystopwords))
print(mystopwords)

# %%
#stopwordsdict={}
#for stop in mystopwords:
#    stopwordsdict[stop] = 1

# %%
Bag=[]
for word in tokens:
    if word not in mystopwords and word.isnumeric()==False and len(word)>2:
        Bag.append(word)

# %%
print(len(Bag))

# %%
SnowStem = SnowballStemmer('english')
Lemmatiser = WordNetLemmatizer()

# %%
import nltk
nltk.download('wordnet')

# %%
Stembag = []
Lembag = []
for word in Bag:
    Stembag.append(SnowStem.stem(word))
    Lembag.append(Lemmatiser.lemmatize(word))
    

# %%
print(Bag[:20])
print(Stembag[:20])
print(Lembag[:20])

# %%
mydict = {}
for word in Stembag:
    if word in mydict.keys():
        mydict[word] +=1
    else:
        mydict[word] = 1

# %%
mydict1 = {}
for word in Lembag:
    if word in mydict1.keys():
        mydict1[word] +=1
    else:
        mydict1[word] = 1

# %%
print(mydict)

# %%
print(mydict1)

# %%
sortedDict = sorted(mydict.items(),key=lambda x:x[1],reverse=True)
print(sortedDict[:100])

# %%
for x in sortedDict[:100]:
    print(x)

# %%
sortedDict = sorted(mydict1.items(),key=lambda x:x[1],reverse=True)
print(sortedDict[:100])


