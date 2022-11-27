#User function Template for python3
class Solution:
    def addBinary(self, A: str, B: str) -> str:
        return bin(int(A,2)+int(B,2))[2:]# code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		a,b = input().split(" ")
		ob = Solution()
		answer = ob.addBinary(a,b)
		
		print(answer)


# } Driver Code Ends