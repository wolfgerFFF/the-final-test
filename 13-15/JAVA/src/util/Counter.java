package util;

public class Counter implements AutoCloseable {
    private int count;
    private boolean resourceClosed;

    public Counter() {
        this.count = 0;
        this.resourceClosed = false;
    }
    
    public int add() throws Exception {
        if (resourceClosed) {
            throw new Exception("Ресурс счетчика уже закрыт");
        }
        return ++count;
    }
    
    @Override
    public void close() {
        resourceClosed = true;
    }
    
    public boolean isResourceClosed() {
        return resourceClosed;
    }
}
