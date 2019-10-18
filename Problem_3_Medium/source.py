class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# solution
def serialize(root):
    if root is None:
        return ''
    return root.val + '(' + serialize(root.left) + ')(' + serialize(root.right) + ')'

def deserialize(s):
    if(s == ''):
        return None
    i = 0
    while(s[i] != '('):
        i += 1

    depth = 1
    j = i+1
    while(depth != 0):
        depth += (s[j] == '(') - (s[j] == ')')
        j += 1
    
    # at this point s[i] = s[j] = '(' both selected at the least depth
    return Node(s[0:i], deserialize(s[i+1:j-1]), deserialize(s[j+1: -1]))


# testing
node = Node('root', Node('left', Node('left.left')), Node('right'))

print(serialize(node))
print(serialize(deserialize(serialize(node))))

# outputs
# root(left(left.left()())())(right()())

assert deserialize(serialize(node)).left.left.val == 'left.left'