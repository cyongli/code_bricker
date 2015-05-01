
import java.io.File;
import java.io.IOException;
import java.util.Random;

import org.apache.lucene.document.Document;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.MultiFields;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.util.Bits;


public class LuceneRandomDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			//Directory index = new RAMDirectory();
			FSDirectory index = FSDirectory.open(new File(args[0]));
			IndexReader reader = DirectoryReader.open(index);
			Random rand = new Random();
			int docId = rand.nextInt(reader.maxDoc());
			System.out.println(reader.maxDoc());
			IndexSearcher searcher = new IndexSearcher(reader);
			Bits liveDocs = MultiFields.getLiveDocs(reader);
			if(liveDocs.get(docId)){
				Document d = searcher.doc(docId);
				System.out.println("docId:" + docId + "\t" + d.get("isbn") + "\t" + d.get("title"));
			}
			else{
				System.out.println("dodId:" + docId);
			}
			reader.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
}

