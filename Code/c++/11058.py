n= int(input())
arr = [{1:1},{1:1}]


for i in range(n-1):
    t = i%2
    # 0, 1, 0, 1 ...
    for key in arr[1-t]:
        arr[1-t][key] = key
        
    for key in arr[t]:
        newVal = arr[t][key] +key
        presentVal = arr[1-t].get(newVal,0)
        if presentVal < arr[t][key]:
            arr[1-t][newVal] = arr[t][key]
            
    keys= list(arr[1-t].keys())
    keys.sort(reverse=True)
    pkey=keys[0]
    pvalue=arr[1-t][pkey]
    for key in keys:
        if key< pkey and arr[1-t][key]<=pvalue:
            arr[1-t].pop(key)
            continue
        pkey = key
        pvalue = arr[1-t][key]

keys= list(arr[1-n%2].keys())
keys.sort(reverse=True)
print(keys[0])