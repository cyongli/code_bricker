package testHBase;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.hbase.HBaseConfiguration;
import org.apache.hadoop.hbase.HColumnDescriptor;
import org.apache.hadoop.hbase.HTableDescriptor;
import org.apache.hadoop.hbase.MasterNotRunningException;
import org.apache.hadoop.hbase.TableName;
import org.apache.hadoop.hbase.ZooKeeperConnectionException;
import org.apache.hadoop.hbase.client.HBaseAdmin;
import org.apache.hadoop.hbase.client.HTable;
import org.apache.hadoop.hbase.client.Put;


public class TestHBase {

	static String hbase_xml = "/home/chaoyli/hbase/conf/hbase-site.xml";
	public static Configuration configuration;
	static {
	    configuration = HBaseConfiguration.create();
	    configuration.set("hbase.zookeeper.property.clientPort", "2181"); 
        configuration.set("hbase.zookeeper.quorum", "localhost");
        configuration.set("hbase.master", "localhost:60000");
	}
		
	public boolean createTable(String tableName){
		try {
			HBaseAdmin admin = new HBaseAdmin(configuration);
			if(admin.tableExists(tableName)){
				System.out.println(tableName + " is exist,no need to create");
				admin.close();
				return false;
			}
					
			HTableDescriptor tableDes = new HTableDescriptor(TableName.valueOf(tableName));
			HColumnDescriptor colDes = new HColumnDescriptor("cf");
			colDes.setMaxVersions(5);
			tableDes.addFamily(colDes);
			admin.createTable(tableDes);
			admin.close();
		} catch (MasterNotRunningException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ZooKeeperConnectionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
						
		return true;
	}

	public boolean deleteTable(String tableName){
		HBaseAdmin admin;
		try {
			admin = new HBaseAdmin(configuration);
			if(admin.tableExists(tableName) == false){
				System.out.println(tableName+" not exist,no need to delete!");
				admin.close();
				return false;
			}
			admin.disableTable(tableName);
			admin.deleteTable(tableName);
			admin.close();
		} catch (MasterNotRunningException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ZooKeeperConnectionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return true;
	}
	
    public boolean storeRecords(String tableName, String row, String columnFamily, String qualifier, String record){
    	try {
			HTable table = new HTable(configuration,tableName);
			Put putRow = new Put(row.getBytes());
			putRow.add(columnFamily.getBytes(), qualifier.getBytes(), record.getBytes());
			table.put(putRow);
			table.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return true;
    }

    public static void main(String[] args){
    	TestHBase t = new TestHBase();
    	String tableName = "test";
    	
    	//t.deleteTable(tableName);
    	t.createTable(tableName);
    	for(int i=0;i<3;i++){
    		t.storeRecords(tableName, "row"+i, "cf", "a", "value"+i);
    	}
    	System.out.println("insert records successfully!");

    }

}

