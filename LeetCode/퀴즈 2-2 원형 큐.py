class MyCircularQueue(object):

    def __init__(self, k):
        # 배열 정의
        self.q = [-1]*(k+1)
        self.rear = 0
        self.front = 0
        self.k = k+1
        

    def enQueue(self, value):
        if self.isFull():
            return False
        # rear를 한 칸 앞으로 이동시키고 그 자리에 value 넣기
        self.rear = (self.rear+1) % self.k
        self.q[self.rear] = value
        return True
        

    def deQueue(self):
        if self.isEmpty():
            return False
        # 첫 번째 원소인 front 바로 다음 칸을 비우고 front를 한 칸 앞으로 이동
        self.q[(self.front+1) % self.k] = -1
        self.front = (self.front+1) % self.k
        return True
        

    def Front(self):
        # 첫 번째 원소는 front 바로 다음 칸
        return self.q[(self.front+1) % self.k]
        

    def Rear(self):
        return self.q[self.rear]
        

    def isEmpty(self):
        return self.rear == self.front
        

    def isFull(self):
        # rear 뒤로 한 칸 이동했을 때 front와 동일할 경우 큐가 가득 참
        return (self.rear+1) % self.k == self.front
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()