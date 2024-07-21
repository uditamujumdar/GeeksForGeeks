<h2><a href="https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/0">N meetings in one room</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">There is <strong>one</strong> meeting room in a firm. There are <strong>n</strong> meetings in the form of <strong>(start[i], end[i])</strong> where <strong>start[i]&nbsp;</strong>is start time of meeting <strong>i </strong>and <strong>end[i] </strong>is finish time of meeting <strong>i.</strong><br>What is the <strong>maximum</strong> number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? </span><span style="font-size: 18px;">Return the <strong>maximum</strong>&nbsp;number of meetings that can be held in the meeting room.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Note:</strong>&nbsp;Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.</span></p>
<p><br><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
<strong>Output: </strong>4<strong>
Explanation: </strong>Maximum four meetings can be held with given start and end timings.</span> <span style="font-size: 18px;">The meetings are - (1, 2),(3, 4), (5,7) and (8,9)</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
<strong>Output: </strong>1<strong>
Explanation: </strong>Only one meetings can be held with given start and end timings.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity </strong>: O(n*Logn)</span><br><span style="font-size: 18px;"><strong>Expected Auxilliary Space</strong> : O(n)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 ≤ n ≤ 10<sup>5</sup></span><br><span style="font-size: 18px;">0 ≤ <strong>star</strong>t<strong>[i]</strong> &lt; <strong>end[i]</strong>&nbsp;≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Cisco</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Greedy</code>&nbsp;<code>Algorithms</code>&nbsp;