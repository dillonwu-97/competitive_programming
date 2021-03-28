class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # find the first element with at least one greater element to its 
            right
        i = 0
        while (i < len(nums)-1 and nums[i] >= nums[i+1]) :
            i+=1
            continue
                    if i == len(nums)-1:
            nums.sort()
        else:
            track = -1
            index = nums[-1]
            stack = [nums[-1]]
            sindex = [len(nums)-1]
            for i in range(len(nums)-2, -1, -1):
                if nums[i] < stack[-1]:
                    track = i
                    break
                else:
                    stack.append(nums[i])
                    sindex.append(i)
            # find the element that is greater than current
            swap_index = -1
            for i in range(len(stack)-1, -1, -1):
                if stack[i] > nums[track]:
                    swap_index = sindex[i]
                else:
                    break
                        # print (stack, swap_index, track)
            # swap the element at swap_index forward until you hit track
            j = swap_index
            while(j > track):
                nums[j], nums[j-1] = nums[j-1], nums[j]
                j-=1    
                        # print(nums)
            # sort everything after track
            swap_index = track+1
            # print("nums ", nums)
            for k in range(track+1, len(nums)):
                                # print(k, nums[j], nums[j-1], i)
                j = k
                while (j > swap_index and nums[j] < nums[j-1]):
                    nums[j], nums[j-1] = nums[j-1], nums[j]
                    j-=1
                                                                                                            #         # if descending order, sort
#         # else find the number where it stops decreasing
#         # afterwards, find the largest number, and look at the number 
    immediately BEFORE that one
#         # find the biggest number greater than BEFORE num
#         # do an insert in the position, and a shift
#         i = 0
#         # stop at place where nums[i] < nums[i+1] or i is last element
#         while (i < len(nums)-1 and nums[i] >= nums[i+1]) :
#             i+=1
#             continue
            #         if i == len(nums)-1:
#             nums.sort()
#         else:
#             # increase starts at i, find the largest num after i
#             max_num = 0
#             max_dex = 0
#             j = i
#             while (j < len(nums)):
#                 if nums[j] > max_num:
#                     max_num = nums[j]
#                     max_dex = j
#                 j+=1
#             # print(max_dex, max_num)
            #             # take the element to the left of max_dex
#             current = nums[max_dex - 1]
#             nex = nums[max_dex]
#             nex_pos = max_dex
#             # print(current, nex)
# #             # find smallest num greater than current
#             j = max_dex
#             while (j < len(nums)):
#                 if nex > nums[j] and nums[j] > current:
#                     nex = nums[j]
#                     nex_pos = j
#                 j+=1
#             # print(nex, nex_pos)
#             # print(nums)
#             #swap
#             j = nex_pos
#             # print("maxdex -1 is ", max_dex-1, max_dex, nex_pos)
#             while(j > max_dex-1):
#                 nums[j], nums[j-1] = nums[j-1], nums[j]
#                 j-=1
# #             # swap
#             # print(nums, max_dex)
#             # sort the rest of them
#             i = max_dex-1
#             for k in range(i+2, len(nums)):
#                 j = k
#                 # print(k, nums[j], nums[j-1], i)
#                 while (j > i+1 and nums[j] < nums[j-1]):
#                     nums[j], nums[j-1] = nums[j-1], nums[j]
#                     j-=1
                                            #             # print(nums[i+1:])
#             # nums[i+1:].sort()
            # #     # [5,4,1,1,3,2]
                                