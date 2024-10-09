dx=tx-x,dy=ty-y;    //还差多少
            cout<<"进else了p="<<p<<endl;
            while(dx){
                if(dx>0 && L>0){
                    dx--;L--;
                }else if(dx<0 && R>0){
                    dx++;R--;
                }
                if(!L && !R){
                    break;
                }
            }