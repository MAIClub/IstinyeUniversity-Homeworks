import numpy
import pandas as pd

class NavieBayes:
    """
        Naive Bayes Implementation
        @input: pandas df
    """

    def __init__(self, df):
        self.df = df
        self.X = df.iloc[:,0:-1].values
        self.y = df.iloc[:,-1].values
        self.numOfClasses = len(self.y)
        self.yLabel = df.columns[-1]
        unique, counts = numpy.unique(self.y, return_counts=True)
        self.classes = dict(zip(unique, counts))
    

    def priorProbability(self, label):
        return self.classes[label] / self.numOfClasses
    
    
    def conditionalProbability(self, point):
        cProbDict = {}
        columns = list(self.df.columns)
        for colName, value in zip(columns,point):
            for label, labelCount in self.classes.items():
                x = self.df.loc[(self.df[colName] == value) & (self.df[self.yLabel] == label)].values
                prob = len(x) / labelCount
                try:
                    cProbDict[label] *= prob
                except KeyError:
                    cProbDict[label] = prob
        
        return cProbDict

    def predict(self, dataPoint):
        print(f"predicting the point {dataPoint}")
        cPropDict = self.conditionalProbability(point)
        result = {k: self.priorProbability(k)*v for k, v in cPropDict.items()}
        pred = max(result, key=result.get)
        print(f'predicted class label is {pred}')
        return pred

if __name__ == "__main__":

    age = 'youth,youth,middle_aged,senior,senior,senior,middle_aged,youth,youth,senior,youth,middle_aged,middle_aged,senior'.split(',')
    income = 'high,high,high,medium,low,low,low,medium,low,medium,medium,medium,high,medium'.split(',')
    student = 'no,no,no,no,yes,yes,yes,no,yes,yes,yes,no,yes,no'.split(',')
    credit_rating = 'fair,excellent,fair,fair,fair,excellent,excellent,fair,fair,fair,excellent,excellent,fair,excellent'.split(',')
    buys_computer = 'no,no,yes,yes,yes,no,yes,no,yes,yes,yes,yes,yes,no'.split(',')

    dataset ={'age':age,'income':income,'student':student,'credit_rating':credit_rating,'buys_computer':buys_computer}
    df = pd.DataFrame(dataset,columns=['age','income','student','credit_rating','buys_computer'])

    point = ['youth', 'medium', 'yes', 'fair']

    nb = NavieBayes(df)
    nb.predict(point)