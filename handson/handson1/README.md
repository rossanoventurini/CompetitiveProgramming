# Hands-on #1
 
## Sliding Window Maximum problem
In this hands-on, we are going to experiment with different solutions for the  *Sliding Window Maximum* problem. 
Folder *sliding_window_maximum* contains two brute force implementations for this problem, tests to check their correctness and 
a file ```main.rs``` to compare their performance on vectors with different sizes.

You are asked to implement the following three asymptotically faster solutions:

- PriorityQueue-based solution with time complexity $\Theta(n \log n)$. **Implement** this solution in function ```pub fn heap(nums: &Vec<i32>, k: i32) -> Vec<i32>```. 
- BBST-based solution with time complexity $\Theta(n \log k)$. **Implement** this solution in function ```pub fn bst(nums: &Vec<i32>, k: i32) -> Vec<i32>```. 
- Deque-based solution with time complexity $\Theta(n)$. **Implement** this solution in function ```pub fn linear(nums: &Vec<i32>, k: i32) -> Vec<i32>```. 

Your goal is to implement these functions in the ```src/lib.rs``` file. Their signatures match the requirements at [LeetCode](https://leetcode.com/problems/sliding-window-maximum/) to allow you to submit any implementation to this site. 
Each implementation starts with an ugly ```let k = k as usize;``` which is necessary to avoid many annoying casts.

File ```src/lib.rs``` contains some tests to check the correctness of you implementation. Feel free to add more tests if needed.
You can check the correctness of your implementation by removing the line ```#[ignore]``` before a test you are ready to activate. 
For example, 
```
#[ignore]
#[test]
fn check_bst_version() {
    ...
```
will skip correctness tests on the ```bst``` implementation while 
```
#[test]
fn check_bst_version() {
    ...
```
will perform it. 

To run tests, execute
```
cargo test
```
and check the output. 
As an example, the following output

![Sample Output](imgs/test_passed.png)

indicates that the linear version test has successfully been executed while the bst and the pqueue tests have been ignored.


## Performance
Once your code successfully passes the complete test suite, you can visualize the performance of your algorithms on random data. 
Run

``` cargo run```

to execute the code inside ```main.rs```. 
This measures the execution time of the different implementations by varying the value of k and the size of the vector. 
Results are reported on a *results.csv* file. 
You can look at this file with any other text editor (e.g., ```nano```). 
We provide a *PlotResults.ipynb* Jupyter notebook to visualize the results. [Install](https://jupyter.org/install) Jupyter lab and run 

```jupyter-lab``` 

to launch the notebook. Make sure that you have all the required libraries installed by running the cell 

```
!{sys.executable} -m pip install seaborn
!{sys.executable} -m pip install pandas
```

[Seaborn](https://seaborn.pydata.org/) is an awesome data visualization library built on the library ```Matplolib```. 

Read the *.csv* file using [Pandas](https://pandas.pydata.org) - a popular Python Data Analysis Library -

```python
results_df = pd.read_csv(result_path)
```

and then plot using

```python
sns.scatterplot(x="k", y="elapsed", hue="Method", data=results_df).
```

### Code optimization

Rust provides various options for compiling code. The command ```cargo build``` compiles code in debug mode with the minimum 
level of optimizations. 
The command ```cargo build --release``` instead optimizes the code at the cost of an increased compile time.
Finally, the command ```RUSTFLAGS='-C target-cpu=native' cargo build --release``` optimizes the code using all the features 
(e.g., latest available SIMD instructions set) of your CPU.

We encourage you to **experiments with these three different optimization levels**.

### Best/Worst cases

Performance are measured on randomly initialized vectors  (```gen_random_vector``` function in ```main.rs```). Think about the __best__ and the __worst__ input configurations for each of the proposed algorithms and measure their performance by adding customized inputs. What is the difference, in terms of execution time, between the best, the worst, and the average scenario? Write your considerations in your report. 

# Submission
Submit the file ```lib.rs``` and a file ```SWM_solution_YOUR_NAME.pdf``` to [rossano.venturini@gmail.com](mailto:rossano.venturini@gmail.com) by 19/10/2022. 

- Source code ```lib.rs``` contains your implementations.
- A report ```SWM_solution_YOUR_NAME.pdf``` that briefly describes your implementations and provides a detailed analysis of the experimental results. In the report, you should try to answer questions like *What's the fastest solution with small values of $k$ and $n$? Why? What's the difference when you increase $k$ or $n$? Do ```--release``` and ```target-cpu=native``` improve the running time? Is the 1-line idiomatic implementation of the brute force solution slower than the other longer one? Is BST-based solution faster than Heap-based one? Are you able to explain this result? Is linear time solution always the fastest?*, and so on. Feel free to modify the Jupyter notebook to better answer those (and other different) questions. The .pdf should be roughly 2 pages (feel free to include plots, if needed).

Before submitting your solutions, 
- make sure your implementation successfully passes all the tests.
- use ```cargo fmt``` to format your code. 
- use ```cargo clippy``` to check your code.
- use [Grammarly](https://grammarly.com/) to improve your English and avoid [tpyos](https://en.wiktionary.org/wiki/tpyo#English) :-). There is an [extension for vscode](https://marketplace.visualstudio.com/items?itemName=znck.grammarly).  

## Cheating
**Very important!** You are allowed to discuss verbally solutions with other
students, **BUT** you have to implement all the solutions by yourself. 
Thus, sharing implementations with others is strictly **forbidden**.
