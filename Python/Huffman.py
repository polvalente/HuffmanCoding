class Huffman:
    def __init__(self, textOrFreqs):
        if(type(textOrFreqs) == type('')):
            self.text = textOrFreqs
            self.frequencies = {}
            self.getFrequencies()
        else:
            self.frequencies = textOrFreqs

    def getFrequencies(self):
        frequencies = {}
        for e in list(self.text):
            if e in frequencies:
                frequencies[e] += 1
            else:
                frequencies[e] = 1
        self.frequencies = frequencies

    def frequenciesToTree(self):
        return map(list, zip(self.frequencies.keys(), self.frequencies.values(), ['' for _ in self.frequencies], [None for _ in self.frequencies]))

    def sortByFrequencies(self, tree):
        #tree is list of lists of type: [char, freq, value, children]
        return sorted(tree, key=lambda x: x[1], reverse=True)

    def reduceTree(self, tree):
        a = tree[-2]
        b = tree[-1]

        new_symbol = [a[0]+b[0], a[1] + b[1], '', [a, b]]
        
        tree = tree[:-1]
        tree[-1] = new_symbol
        return tree;

    def traverseTreeAndAssign(self, tree, value=''):
        #tree is list of lists of type: [char, freq, value, children]
        tree[2] = value
        if tree[3] is None: return tree
        self.traverseTreeAndAssign(tree[3][0],tree[2]+'0')
        self.traverseTreeAndAssign(tree[3][1],tree[2]+'1')
        return 

    def getAlphabet(self, tree, alphabet):
        if tree[3] is None: 
            alphabet.append((tree[0], tree[2]))
            return
            #return [(tree[0], tree[2])]
        self.getAlphabet(tree[3][0], alphabet)
        self.getAlphabet(tree[3][1], alphabet)
        #alphabet.extend(self.getAlphabet(tree[3][0], alphabet))
        #alphabet.extend(self.getAlphabet(tree[3][1], alphabet))
        #return alphabet

    def encode(self):
        tree = self.frequenciesToTree()
        while(len(tree) > 1):
            tree = self.sortByFrequencies(tree)
            tree = self.reduceTree(tree)

        tree = tree[0]
        self.traverseTreeAndAssign(tree)
        self.tree = tree

        self.alphabet = []
        self.getAlphabet(self.tree, self.alphabet)
        self.alphabet = sorted(self.alphabet, key=lambda x: x[0])




if __name__ == "__main__":
    from sys import argv
    txt = ""
    if len(argv) < 3:
        print "Usage: %s <string> ['filename']" % argv[0]

    if argv[2] == "filename":
        l = {}
        with open(argv[1], 'r') as f:
            for line in f.readlines():
                line = line.split()
                c = line[0]
                n = int(line[1])
                l[c] = n
        #tree is list of lists of type: [char, freq, value, children]
        h = Huffman(l)

    else:
        txt = argv[1]
        h = Huffman(txt)

    h.encode()
    print 'Frequencies:', h.frequencies
    print
    print 'Alphabet:'
    for c in h.alphabet:
        print c
