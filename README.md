In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needed to be replaced when new page comes in. Whenever a new page is referred and not present in memory, page fault occurs and Operating System replaces one of the existing pages with newly needed page. Different page replacement algorithms suggest different ways to decide which page to replace. The target for all algorithms is to reduce number of page faults.In Least Recently Used (LRU) algorithm is a Greedy algorithm where the page to be replaced is least recently used.



The idea is based on locality of reference, the least recently used page is not likely 
Let say the page reference string 7 0 1 2 0 3 0 4 2 3 0 3 2 . Initially we have 4 page slots empty. 
Initially all slots are empty, so when 7 0 1 2 are allocated to the empty slots —> 4 Page faults 
0 is already there so —> 0 Page fault. 
when 3 came it will take the place of 7 because it is least recently used —>1 Page fault 
0 is already in memory so —> 0 Page fault. 
4 will takes place of 1 —> 1 Page Fault 
Now for the further page reference string —> 0 Page fault because they are already available in the memory.





Let capacity be the number of pages that
memory can hold.  Let set be the current
set of pages in memory.

1- Start traversing the pages.
 i) If set holds less pages than capacity.
   a) Insert page into the set one by one until 
      the size  of set reaches capacity or all
      page requests are processed.
   b) Simultaneously maintain the recent occurred
      index of each page in a map called indexes.
   c) Increment page fault
 ii) Else 
   If current page is present in set, do nothing.
   Else 
     a) Find the page in the set that was least 
     recently used. We find it using index array.
     We basically need to replace the page with
     minimum index.
     b) Replace the found page with current page.
     c) Increment page faults.
     d) Update index of current page.
2. Return page faults.
