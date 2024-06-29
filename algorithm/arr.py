array=[2,3,4,5,6,6,7,2,2,8,6,65,34,2,7,8,9]
newArray={}
for i in range(0,len(array)-1,1):
    count = 1
    for j in range(i+1,len(array),1):
        if array[i]==array[j]:
            count+=1
    if count>=2 and array[i] not in newArray:
        newArray.update({array[i]:count})
for key,value in newArray.items():
    print(key,":",value)
                                        