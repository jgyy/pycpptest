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
    if not target:
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
    n = len(matrix)
    
    # Transpose the matrix
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    
    # Reverse each row
    for i in range(n):
        matrix[i] = matrix[i][::-1]
    
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
    if not nums:
        return 0
        
    num_set = set(nums)
    longest = 0
    
    for num in num_set:
        if num - 1 not in num_set:  # Start of a sequence
            current = num
            current_streak = 1
            
            while current + 1 in num_set:
                current += 1
                current_streak += 1
            
            longest = max(longest, current_streak)
    
    return longest


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
    def is_valid_bst(node, min_val=float('-inf'), max_val=float('inf')):
        if not node:
            return True
            
        if node.val <= min_val or node.val >= max_val:
            return False
            
        return (is_valid_bst(node.left, min_val, node.val) and 
                is_valid_bst(node.right, node.val, max_val))
    
    return is_valid_bst(root)


# TreeNode class definition for Task 4
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Test cases
def run_tests():
    # Test Task 1: Count Substrings
    assert count_substrings("banana", "ana") == 2
    assert count_substrings("hello hello", "hello") == 2
    assert count_substrings("aaaaa", "aa") == 4
    assert count_substrings("python", "java") == 0
    
    # Test Task 2: Rotate Matrix
    matrix1 = [[1,2],[3,4]]
    assert rotate_matrix(matrix1) == [[3,1],[4,2]]
    
    matrix2 = [[1,2,3],[4,5,6],[7,8,9]]
    assert rotate_matrix(matrix2) == [[7,4,1],[8,5,2],[9,6,3]]
    
    # Test Task 3: Longest Consecutive Sequence
    assert longest_consecutive_sequence([100,4,200,1,3,2]) == 4
    assert longest_consecutive_sequence([0,3,7,2,5,8,4,6,1]) == 9
    assert longest_consecutive_sequence([]) == 0
    assert longest_consecutive_sequence([1]) == 1
    
    # Test Task 4: Validate BST
    # Create test cases for BST validation
    bst1 = TreeNode(2)
    bst1.left = TreeNode(1)
    bst1.right = TreeNode(3)
    assert validate_binary_search_tree(bst1) == True
    
    bst2 = TreeNode(5)
    bst2.left = TreeNode(1)
    bst2.right = TreeNode(4)
    bst2.right.left = TreeNode(3)
    bst2.right.right = TreeNode(6)
    assert validate_binary_search_tree(bst2) == True
    
    print("All tests passed!")


if __name__ == "__main__":
    run_tests()
