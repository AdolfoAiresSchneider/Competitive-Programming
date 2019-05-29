
   public class triple{
        int st, nd;
        boolean flag;
        public triple(int a, int b, boolean c){
            this.st = a;
            this.nd = b;
            this.flag = c;
        }
       public triple(boolean a){
           this.flag = a;
           this.nd = Integer.MAX_VALUE;
           this.st = Integer.MIN_VALUE;
       }
    }

    triple c1(Node root){
        if(root == null) return new triple(true);
        triple L = c1(root.left);
        triple R = c1(root.right);
        if(root.data <= L.st || root.data >= R.nd) return new triple(false);
        triple sub = new triple(false);
        sub.st = Math.max(L.st, Math.max(R.st, root.data));
        sub.nd = Math.min(L.nd, Math.min(R.nd, root.data));
        sub.flag = L.flag && R.flag;
        return sub;
    }

    boolean checkBST(Node root) {
        return c1(root).flag;
    }
