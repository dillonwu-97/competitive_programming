# Modify the bs, replace return -1 with return r
def binary_search(alist, start, end, key):
    """Search key in alist[start... end - 1]."""
    if not start < end:
        return -1
 
    mid = (start + end)//2
    if alist[mid] < key:
        return binary_search(alist, mid + 1, end, key)
    elif alist[mid] > key:
        return binary_search(alist, start, mid, key)
    else:
        return mid
 

# This should return the index of the number greater than the one we're looking for
def binary_searchG(alist, start, end, key):
    """Search key in alist[start... end - 1]."""
    if not start < end:
        return start
 
    mid = (start + end)//2
    if alist[mid] < key:
        return binary_searchG(alist, mid + 1, end, key)
    elif alist[mid] > key:
        return binary_searchG(alist, start, mid, key)
    else:
        return mid
 

# This should return the index of the number less than the one we're looking for
def binary_searchL(alist, start, end, key):
    """Search key in alist[start... end - 1]."""
    if not start < end:
        return end
 
    mid = (start + end)//2
    if alist[mid] < key:
        return binary_searchL(alist, mid + 1, end, key)
    elif alist[mid] > key:
        return binary_searchL(alist, start, mid, key)
    else:
        return mid
 