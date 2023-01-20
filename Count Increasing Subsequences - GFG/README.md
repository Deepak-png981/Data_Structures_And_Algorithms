# Count Increasing Subsequences
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of digits (values lie in range from 0 to 9). The task is to count all the sub sequences possible in array such that in each subsequence every digit is greater than its previous digits in the subsequence.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : </strong>
a[] = {1, 2, 3, 4}
<strong>Output: </strong>
15
<strong>Explanation :</strong>
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4},
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4},
{1,3,4}, {2,3,4}, {1,2,3,4}</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : </strong>
a[] = {4, 3, 6, 5}
<strong>Output:</strong>
8
<strong>Explanation :</strong>
Sub-sequences are {4}, {3}, {6}, {5},
{4,6}, {4,5}, {3,6}, {3,5}</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 3:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : </strong>
a[] = {3, 2, 4, 5, 4}
<strong>Output : </strong>
14
<strong>Explanation :</strong>
Sub-sequences are {3}, {2}, {4}, {3,4},
{2,4}, {5}, {3,5}, {2,5}, {4,5}, {3,2,5}
{3,4,5}, {4}, {3,4}, {2,4}</span>
</pre>

<p><br>
<br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't have to print anything, printing is done by the driver function. You have to complete the function <strong>countSub() </strong>which takes the array <strong>a[]</strong> and its size <strong>N</strong><strong> </strong>as inputs and returns the count of all increasing subsequences in given array of digits.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O( max(a[i]) ) = O(10)</span><br>
<br>
<br>
<span style="font-size:18px"><strong>Constraints: </strong><br>
1 ≤ N ≤ 500<br>
1 ≤ a[i] ≤ 9</span></p>
</div>