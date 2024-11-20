# Python Coding Test 2
# Time limit: 60 minutes
# Instructions: Complete all the functions below according to their specifications.
# Each function has its own test cases that must pass.

def count_substrings(s: str, target: str) -> int:
    """
    Task 1: Count the number of occurrences of a substring in a string.
    Do not use built-in count() method.
    Args:
        s (str): Main string
        target (str): Substring to count
    Returns:
        int: Number of occurrences of target in s
    Example:
        >>> count_substrings("banana", "ana")
        2
    """
    # TODO: Implement this function
    if not s or not target:
        return 0
    count = 0
    for i in range(len(s) - len(target) + 1):
        if s[i:i + len(target)] == target:
            count += 1
    return count


def rotate_matrix(matrix: list) -> list:
    """
    Task 2: Rotate a square matrix 90 degrees clockwise.
    The rotation should be done in-place if possible.
    Args:
        matrix (List[List[int]]): Square matrix to rotate
    Returns:
        List[List[int]]: Rotated matrix
    Example:
        >>> rotate_matrix([[1,2],[3,4]])
        [[3,1],[4,2]]
    """
    # TODO: Implement this function
    n = len(matrix);
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(n):
        matrix[i].reverse()
    return matrix


def longest_consecutive_sequence(nums: list) -> int:
    """
    Task 3: Find the length of the longest consecutive sequence in an unsorted list.
    Time complexity should be O(n).
    Args:
        nums (List[int]): List of unsorted integers
    Returns:
        int: Length of longest consecutive sequence
    Example:
        >>> longest_consecutive_sequence([100,4,200,1,3,2])
        4  # The longest consecutive sequence is [1,2,3,4]
    """
    # TODO: Implement this function
    if not nums:
        return 0
    num_set = set(nums)
    max_length = 0
    for num in num_set:
        if num - 1 not in num_set:
            current_num = num
            current_length = 1
            while current_num + 1 in num_set:
                current_num += 1
                current_length += 1
            max_length = max(max_length, current_length)
    return max_length


# TreeNode class definition for Task 4
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def validate_binary_search_tree(root: 'TreeNode') -> bool:
    """
    Task 4: Validate if a binary tree is a valid binary search tree (BST).
    A valid BST has the following properties:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
    Args:
        root: Root node of the binary tree
    Returns:
        bool: True if the tree is a valid BST, False otherwise
    """
    # TODO: Implement this function
    def is_valid_bst(node: 'TreeNode', min_val: float, max_val: float) -> bool:
        if not node:
            return True
        if node.val <= min_val or node.val >= max_val:
            return False
        return (is_valid_bst(node.left, min_val, node.val) and
                is_valid_bst(node.right, node.val, max_val))

    return is_valid_bst(root, float('-inf'), float('inf'))


# Test cases
def run_tests():
    print("Running Task 1 tests...")
    # Test Task 1: Count Substrings
    assert count_substrings("banana", "ana") == 2, "Test 1.1 failed"
    assert count_substrings("hello hello", "hello") == 2, "Test 1.2 failed"
    assert count_substrings("aaaaa", "aa") == 4, "Test 1.3 failed"
    assert count_substrings("python", "java") == 0, "Test 1.4 failed"
    # Additional test cases for Task 1
    assert count_substrings("", "test") == 0, "Test 1.5 failed: Empty string case"
    assert count_substrings("test", "") == 0, "Test 1.6 failed: Empty target case"
    assert count_substrings("aaa", "aaaa") == 0, "Test 1.7 failed: Target longer than string"
    print("Task 1 tests passed!")

    print("\nRunning Task 2 tests...")
    # Test Task 2: Rotate Matrix
    matrix1 = [[1,2],[3,4]]
    assert rotate_matrix(matrix1) == [[3,1],[4,2]], "Test 2.1 failed"
    
    matrix2 = [[1,2,3],[4,5,6],[7,8,9]]
    assert rotate_matrix(matrix2) == [[7,4,1],[8,5,2],[9,6,3]], "Test 2.2 failed"
    
    # Additional test cases for Task 2
    matrix3 = [[1]]
    assert rotate_matrix(matrix3) == [[1]], "Test 2.3 failed: 1x1 matrix"
    
    matrix4 = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    assert rotate_matrix(matrix4) == [[13,9,5,1],[14,10,6,2],[15,11,7,3],[16,12,8,4]], "Test 2.4 failed: 4x4 matrix"
    print("Task 2 tests passed!")

    print("\nRunning Task 3 tests...")
    # Test Task 3: Longest Consecutive Sequence
    assert longest_consecutive_sequence([100,4,200,1,3,2]) == 4, "Test 3.1 failed"
    assert longest_consecutive_sequence([0,3,7,2,5,8,4,6,1]) == 9, "Test 3.2 failed"
    assert longest_consecutive_sequence([]) == 0, "Test 3.3 failed"
    assert longest_consecutive_sequence([1]) == 1, "Test 3.4 failed"
    # Additional test cases for Task 3
    assert longest_consecutive_sequence([1,2,2,3,4]) == 4, "Test 3.5 failed: Duplicate numbers"
    assert longest_consecutive_sequence([-5,-4,-3,-2,-1,0]) == 6, "Test 3.6 failed: Negative numbers"
    assert longest_consecutive_sequence([1,3,5,7,9]) == 1, "Test 3.7 failed: No consecutive numbers"
    print("Task 3 tests passed!")

    print("\nRunning Task 4 tests...")
    # Test Task 4: Validate BST
    # Test case 1: Valid BST
    bst1 = TreeNode(2)
    bst1.left = TreeNode(1)
    bst1.right = TreeNode(3)
    assert validate_binary_search_tree(bst1) == True, "Test 4.1 failed"

    # Test case 2: Invalid BST (previously incorrect test case, now fixed)
    invalid_bst = TreeNode(5)
    invalid_bst.left = TreeNode(1)
    invalid_bst.right = TreeNode(4)  # This should make it invalid as 4 < 5
    invalid_bst.right.left = TreeNode(3)
    invalid_bst.right.right = TreeNode(6)
    assert validate_binary_search_tree(invalid_bst) == False, "Test 4.2 failed"

    # Additional test cases for Task 4
    # Test case 3: Empty tree
    assert validate_binary_search_tree(None) == True, "Test 4.3 failed: Empty tree"

    # Test case 4: Single node
    single_node = TreeNode(1)
    assert validate_binary_search_tree(single_node) == True, "Test 4.4 failed: Single node"

    # Test case 5: Valid complex BST
    complex_bst = TreeNode(8)
    complex_bst.left = TreeNode(3)
    complex_bst.right = TreeNode(10)
    complex_bst.left.left = TreeNode(1)
    complex_bst.left.right = TreeNode(6)
    complex_bst.right.right = TreeNode(14)
    complex_bst.left.right.left = TreeNode(4)
    complex_bst.left.right.right = TreeNode(7)
    assert validate_binary_search_tree(complex_bst) == True, "Test 4.5 failed: Complex valid BST"

    # Test case 6: Invalid BST (violating BST property in deep level)
    invalid_complex = TreeNode(8)
    invalid_complex.left = TreeNode(3)
    invalid_complex.right = TreeNode(10)
    invalid_complex.left.left = TreeNode(1)
    invalid_complex.left.right = TreeNode(6)
    invalid_complex.right.right = TreeNode(14)
    invalid_complex.left.right.left = TreeNode(7)  # Invalid: 7 > 6
    assert validate_binary_search_tree(invalid_complex) == False, "Test 4.6 failed: Complex invalid BST"

    print("Task 4 tests passed!")
    print("\nAll tests passed successfully!")


if __name__ == "__main__":
    run_tests()
