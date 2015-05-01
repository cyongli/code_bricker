import java.io.File;
import java.io.IOException;

import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.StringField;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.index.Term;
import org.apache.lucene.queryparser.classic.ParseException;
import org.apache.lucene.queryparser.classic.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopScoreDocCollector;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.store.RAMDirectory;
import org.apache.lucene.util.Version;


public class LuceneDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			StandardAnalyzer analyzer = new StandardAnalyzer();
			//Directory index = new RAMDirectory();
			FSDirectory index = FSDirectory.open(new File("/home/chaoyli/test"));
			IndexWriterConfig config = new IndexWriterConfig(Version.LUCENE_4_10_0, analyzer);		

			//1. index
			IndexWriter w = new IndexWriter(index, config);		
			addDoc(w, "Lucene in Action", "193398817");
			addDoc(w, "Lucene for Dummies", "55320055Z");
			addDoc(w, "Managing Gigabytes", "55063554A");
			addDoc(w, "The Art of Computer Science", "9900333X");
			w.close();
		
			//2. query
			String querystr = (args.length > 0) ? args[0] : "Lucene";
			Query q = new QueryParser("title", analyzer).parse(querystr);
			
			//3. search
			int hitsPerPage = 10;
			IndexReader reader = DirectoryReader.open(index);
			IndexSearcher searcher = new IndexSearcher(reader);
			TopScoreDocCollector collector = TopScoreDocCollector.create(hitsPerPage, true);
			searcher.search(q, collector);
			ScoreDoc[] hits = collector.topDocs().scoreDocs;
						
			//4. display results
			System.out.println("Found " + hits.length + " hits.");
			for(int i=0;i<hits.length;++i){
				int docId = hits[i].doc;
				Document d = searcher.doc(docId);
				System.out.println("docId:" + docId + "\t" + d.get("isbn") + "\t" + d.get("title"));
			}
			reader.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void addDoc(IndexWriter w, String title, String isbn){
		Document doc = new Document();
		doc.add(new TextField("title", title, Field.Store.YES));
		doc.add(new StringField("isbn", isbn, Field.Store.YES));
		try {
			w.addDocument(doc);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
