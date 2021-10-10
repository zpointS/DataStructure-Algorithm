#include "hash.h"

int hash(KeyType k)
{
	int h;
	h = k % m;
	return h;
}

int  HashSearch( HashTable  ht,  KeyType  K)
{
	int h0;
	int i;
	int hi;
	
	h0=hash(K);
	if(ht[h0].key==NULLKEY) 
	{
		return (-1);
	}	
	else 
	{
		if (ht[h0].key==K) 
		{
			return (h0);
		}	
		else   /* ������̽����ɢ�н����ͻ */
		{ 
			for (i=1; i<=m-1;  i++)
			{
				hi=(h0+i) % m;
				if  (ht[hi].key==NULLKEY) 
				{
					return (-1);
				}	
				else
				{
					if (ht[hi].key==K) 
					{
						return (hi);
					}	
				}	
			}
			return (-1);
		}
	}		
}
