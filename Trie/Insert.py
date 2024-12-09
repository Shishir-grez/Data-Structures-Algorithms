from typing import Dict

class TrieNode:
    def __init__(self):
        # children is a dictionary where each key is a character (str) and value is a TrieNode
        self.children: Dict[str, 'TrieNode'] = {}  # Using a dictionary to hold children nodes (dynamic allocation)
        self.isEndsWith: bool = False  # To check if the word ends at this node


class Trie:
    def __init__(self):
        self.root: TrieNode = TrieNode()  # The root node of the trie

    def insert(self, word: str) -> None:
        """
        Insert a word into the trie.
        
        :param word: The word to insert into the trie
        :return: None
        """
        node: TrieNode = self.root  # Start at the root node
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()  # Create a new node if not present
            node = node.children[char]  # Move to the child node
        node.isEndsWith = True  # Mark the end of the word

    def search(self, word: str) -> bool:
        """
        Search for a word in the trie.
        
        :param word: The word to search for in the trie
        :return: True if the word exists in the trie, False otherwise
        """
        node: TrieNode = self.root  # Start at the root node
        for char in word:
            if char not in node.children:
                return False  # The word does not exist in the trie
            node = node.children[char]
        return True  # The word exists in the trie


# Type annotation for trie variable
trie: Trie = Trie()  # 'trie' is an instance of the Trie class

# Example usage
trie.insert("hello")
trie.insert("hell")
trie.insert("heaven")
trie.insert("goodbye")

# Search for words
print(f"Search 'hello': {trie.search('hello')}")
print(f"Search 'hell': {trie.search('hell')}")
print(f"Search 'heaven': {trie.search('heaven')}")
print(f"Search 'good': {trie.search('good')}")
