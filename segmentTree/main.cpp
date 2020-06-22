#include <iostream>

using namespace std;
#define MAXN 1000
int arr[MAXN];
int st[4*MAXN+1];

void updateRange(int l,int r,int val,int sr,int er,int index){
    if(sr==er){
        st[index]+=val;
        arr[sr]+=val;
        return;
    }
    int mid=(sr+er)/2;
    if(l<=mid){
        updateRange(l,r,val,sr,mid,2*index+1);
    }
    if(r>=mid+1){
        updateRange(l,r,val,mid+1,er,2*index+2);
    }
    st[index]=min(st[2*index+1],st[2*index+2]);
}

void update(int i,int val,int sr,int er,int index){
    if(sr==er){
        st[index]=st[index]+val;
        arr[i]+=val;
        return;
    }

    int mid=(sr+er)/2;
    if(i>=sr&&i<=mid){
        update(i,val,sr,mid,2*index+1);
    }
    else{
        update(i,val,mid+1,er,2*index+2);
    }
    st[index]=min(st[2*index+1],st[2*index+2]);
}

int query(int l,int r,int sr,int er,int index){
    // Total overlap
    if(l<=sr && r>=er){
        return st[index];
    }
    // No overlap
    if(l>er || r<sr){
        return INT_MAX;
    }

    // Partial overlap
    int mid=(sr+er)/2;
    return min(query(l,r,sr,mid,2*index+1),query(l,r,mid+1,er,2*index+2));
}

void buildst(int sr,int er,int index){
    if(sr==er){
        st[index]=arr[sr];
        return;
    }

    int mid=(sr+er)/2;
    buildst(sr,mid,2*index+1);
    buildst(mid+1,er,2*index+2);
    st[index]= min(st[2*index+1],st[2*index+2]);

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    buildst(0,n-1,0);

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int type;
        cin>>type;

        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans=query(l,r,0,n-1,0);
            cout<<ans<<'\n';
        }
        else if(type==2){
            int index;
            cin>>index;
            int val;
            cin>>val;
            update(index,val,0,n-1,0);
        }
        else{
            int l,r;
            cin>>l>>r;
            int val;
            cin>>val;
            updateRange(l,r,val,0,n-1,0);
        }
    }

    cout<<"DONE";

    return 0;
}
