<h2><a href="https://www.geeksforgeeks.org/problems/dice-throw5349/0">Dice throw</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given <strong>N</strong> dice each with <strong>M</strong> faces, numbered from 1 to M, find the number of ways to get sum <strong>X</strong>. X is the summation of values on each face when all the dice are thrown.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>M = </strong>6, <strong>N = </strong>3, <strong>X =</strong> 12</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">25</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>M = </strong>2, <strong>N = </strong>3, <strong>X =</strong> 6</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">1</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">There is only 1 way to get
the Sum 6 using 3 dices with
faces from 1 to 2. All the
dices will have to land on 2.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>noOfWays()</strong> which takes 3 Integers M,N and X as input and returns the answer.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(M*N*X)<br><strong>Expected Auxiliary Space:</strong> O(N*X)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 &lt;= M,N,X &lt;= 50</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Arrays</code>&nbsp;