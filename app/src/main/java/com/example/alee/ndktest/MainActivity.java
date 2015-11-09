package com.example.alee.ndktest;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        NdkTest ndkTest = new NdkTest();

        TextView tv = (TextView)findViewById(R.id.text_1);
        TextView tv2 = (TextView)findViewById(R.id.text_2);
        TextView tv3 = (TextView)findViewById(R.id.text_3);
        TextView tv4 = (TextView)findViewById(R.id.text_4);
        TextView tv5 = (TextView)findViewById(R.id.text_5);
        TextView tv6 = (TextView)findViewById(R.id.text_6);
        TextView tv7 = (TextView)findViewById(R.id.text_7);
        TextView tv8 = (TextView)findViewById(R.id.text_8);

        TestClass testClass = new TestClass();
        tv.setText(ndkTest.getString(testClass));

        ndkTest.setString(testClass, "Tony Rocks!");
        tv2.setText(ndkTest.getString(testClass));

        tv3.setText("Here is the unmodified int: " + ndkTest.getInteger(testClass));

        ndkTest.setInteger(testClass, 100);
        tv4.setText("Here is the modified int: " + (ndkTest.getInteger(testClass)));

        tv5.setText("Here is the original sub string: " + (ndkTest.getString2(testClass)));

        ndkTest.setString2(testClass, "Tony Rocks Again!");
        tv6.setText("Here is the modified sub string: " + (ndkTest.getString2(testClass)));

        tv7.setText("Here is the original sub int: " + (ndkTest.getInteger2(testClass)));

        ndkTest.setInteger2(testClass, 200);
        tv8.setText("Here is the modified sub int: " + (ndkTest.getInteger2(testClass)));

        ndkTest.setNativeString("Modified Text");
        final String theString = ndkTest.getNativeString();

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, theString, Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
