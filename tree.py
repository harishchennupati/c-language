class Tree:
    def __init__(self,v=None):
        self.value=v
        if self.value:
            self.left=Tree()
            self.right=Tree()
        else:
            self.left=None
            self.right=None
        return

    def isempty(self):
        return(self.value==None)
    def isleaf(self):
        return (self.left.isempty() and self.right().isempty())
    def makeempty(self):
        self.value=None
        self.left=None
        self.right=None
        return
    def copyright(self):
        self.value=self.right.value
        self.left=self.right.left
        self.right=self.right.right
        return 
    def find(self,v):
        if self.isempty():
            return
        if self.value==v:
            retun(True)
        if v<self.value:
            return(self.left.find(v))
        if v>self.value:
            return(self.right.find(v))
    def insert(self,v):
        if self.isempty():
            self.value=v
            self.left=Tree()
            self.right=Tree()
        if self.value==v:
            return()
        if v<self.value:
            self.left.insert(v)
            return
        if v>self.value:
            self.right.insert(v)
            return

    def maxval(self):
        if self.right.isempty():
            return(self.value)
        else:
            return(self.left.maxval())
    def delete(self,v):
        if self.isempty():
            return
        if v<self.value:
            self.left.delete(v)
            return
        if v>self.value:
            self.right.delete(v)
        if v==self.value:
            if self.isleaf():
                self.makeempty()
            elif self.left.isempty():
                self.copyright()
            elif self.right.isempty():
                self.copyleft()
            else:
                self.value=self.left.maxval()
                self.left.delete(self.left.maxval())
                return
    def copyleft(self):
        self.value=self.left.value
        self.left=self.left.left
        self.right=self.right.right
    def inorder(self):
        if self.isempty():
            return([])
        else:
            return (self.left.inorder()+[self.value]+self.right.inorder())
    def __str__(self):
        return(str(self.inorder()))