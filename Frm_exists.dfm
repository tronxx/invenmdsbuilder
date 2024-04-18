object Form_exists: TForm_exists
  Left = 193
  Top = 179
  Width = 728
  Height = 488
  Caption = 'Existencias Avanzadas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 712
    Height = 94
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 712
      Height = 60
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 93
        Height = 60
        Align = alLeft
        TabOrder = 0
        object chk_codigo: TCheckBox
          Left = 2
          Top = 17
          Width = 85
          Height = 17
          Alignment = taLeftJustify
          Caption = '&C�digo'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = chk_codigoClick
        end
        object edt_prcod: TEdit
          Left = 4
          Top = 35
          Width = 84
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
      end
      object GroupBox2: TGroupBox
        Left = 342
        Top = 0
        Width = 74
        Height = 60
        Align = alLeft
        TabOrder = 4
        object edt_prgrp: TEdit
          Left = 2
          Top = 35
          Width = 67
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_grupo: TCheckBox
          Left = 3
          Top = 17
          Width = 66
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Grupo'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
      object GroupBox5: TGroupBox
        Left = 184
        Top = 0
        Width = 84
        Height = 60
        Align = alLeft
        TabOrder = 2
        object edt_prsit: TEdit
          Left = 4
          Top = 35
          Width = 73
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_situac: TCheckBox
          Left = 4
          Top = 17
          Width = 74
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Situaci�n'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 93
        Top = 0
        Width = 91
        Height = 60
        Align = alLeft
        TabOrder = 1
        object edt_prmarca: TEdit
          Left = 4
          Top = 35
          Width = 82
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_marca: TCheckBox
          Left = 4
          Top = 17
          Width = 82
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Marca'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
      object GroupBox6: TGroupBox
        Left = 416
        Top = 0
        Width = 57
        Height = 60
        Align = alLeft
        TabOrder = 5
        object chk_prove: TCheckBox
          Left = 2
          Top = 17
          Width = 49
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Prove'
          TabOrder = 0
          OnClick = chk_codigoClick
        end
        object edt_prprove: TEdit
          Left = 5
          Top = 35
          Width = 46
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
      end
      object GroupBox7: TGroupBox
        Left = 543
        Top = 0
        Width = 169
        Height = 60
        Align = alClient
        Caption = 'Zonas'
        TabOrder = 7
        object Label1: TLabel
          Left = 2
          Top = 18
          Width = 27
          Height = 13
          Caption = 'Inicial'
        end
        object Label2: TLabel
          Left = 7
          Top = 37
          Width = 22
          Height = 13
          Caption = 'Final'
        end
        object lkcmb_zonini: TDBLookupComboBox
          Left = 32
          Top = 12
          Width = 40
          Height = 21
          KeyField = 'ZONA'
          ListField = 'ZONA'
          ListSource = dts_zonini
          TabOrder = 0
        end
        object dbedt_zonini: TDBEdit
          Left = 73
          Top = 12
          Width = 96
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          DataField = 'NOMBRE'
          DataSource = dts_zonini
          TabOrder = 2
          OnDblClick = dbedt_zoniniDblClick
        end
        object lkcmb_zonfin: TDBLookupComboBox
          Left = 32
          Top = 35
          Width = 40
          Height = 21
          KeyField = 'ZONA'
          ListField = 'ZONA'
          ListSource = dts_zonfin
          TabOrder = 1
        end
        object DBEdit2: TDBEdit
          Left = 73
          Top = 35
          Width = 96
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          DataField = 'NOMBRE'
          DataSource = dts_zonfin
          TabOrder = 3
        end
      end
      object GroupBox8: TGroupBox
        Left = 473
        Top = 0
        Width = 70
        Height = 60
        Align = alLeft
        TabOrder = 6
        object chk_linea: TCheckBox
          Left = 3
          Top = 17
          Width = 62
          Height = 17
          Alignment = taLeftJustify
          Caption = '&L�nea'
          TabOrder = 0
          OnClick = chk_codigoClick
        end
        object edt_prlin: TEdit
          Left = 3
          Top = 35
          Width = 62
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 1
        end
      end
      object GroupBox4: TGroupBox
        Left = 268
        Top = 0
        Width = 74
        Height = 60
        Align = alLeft
        TabOrder = 3
        object edt_diary: TEdit
          Left = 2
          Top = 35
          Width = 67
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
        end
        object chk_diary: TCheckBox
          Left = 3
          Top = 17
          Width = 66
          Height = 17
          Alignment = taLeftJustify
          Caption = '&Diary'
          TabOrder = 1
          OnClick = chk_codigoClick
        end
      end
    end
    object Panel4: TPanel
      Left = 0
      Top = 60
      Width = 712
      Height = 34
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object Label19: TLabel
        Left = 6
        Top = 11
        Width = 68
        Height = 13
        Caption = 'Existencias Al '
      end
      object btn_estadis: TBitBtn
        Left = 386
        Top = 6
        Width = 86
        Height = 25
        Caption = 'OK'
        Default = True
        ModalResult = 1
        TabOrder = 0
        OnClick = btn_estadisClick
        Glyph.Data = {
          DE010000424DDE01000000000000760000002800000024000000120000000100
          0400000000006801000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          3333333333333333333333330000333333333333333333333333F33333333333
          00003333344333333333333333388F3333333333000033334224333333333333
          338338F3333333330000333422224333333333333833338F3333333300003342
          222224333333333383333338F3333333000034222A22224333333338F338F333
          8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
          33333338F83338F338F33333000033A33333A222433333338333338F338F3333
          0000333333333A222433333333333338F338F33300003333333333A222433333
          333333338F338F33000033333333333A222433333333333338F338F300003333
          33333333A222433333333333338F338F00003333333333333A22433333333333
          3338F38F000033333333333333A223333333333333338F830000333333333333
          333A333333333333333338330000333333333333333333333333333333333333
          0000}
        NumGlyphs = 2
      end
      object BitBtn1: TBitBtn
        Left = 475
        Top = 6
        Width = 75
        Height = 25
        Caption = '&T�tulo'
        TabOrder = 1
        OnClick = BitBtn1Click
        Kind = bkAll
      end
      object date_fecexis: TDateTimePicker
        Left = 81
        Top = 6
        Width = 104
        Height = 21
        CalAlignment = dtaLeft
        Date = 38236
        Time = 38236
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 2
      end
    end
  end
  object dbgrd_exist: TdxDBGrid
    Left = 0
    Top = 94
    Width = 712
    Height = 355
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    DataSource = dts_exist
    Filter.Criteria = {00000000}
    OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
    OptionsView = [edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    ShowRowFooter = True
    OnCustomDrawCell = dbgrd_existCustomDrawCell
  end
  object qry_estadialm: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select alm, mes, nombre, sum(unidades) from estadis a'
      'join ptovta b on alm=clave and a.cia = b.cia'
      'where '
      '(tipo = :TIPO1 or tipo = :TIPO2) '
      'and anu = :ANU and codigo = :CODIGO and cia=:CIA'
      'group by alm,mes, nombre')
    Left = 244
    Top = 385
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_estadis: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select (codigo + alm) as llave, codigo, alm, NULL as Ene, NULL a' +
        's Feb, NULL as Mar, NULL as Abr, NULL as May, NULL as Jun, '
      
        'NULL as Jul, NULL as Ago, NULL as Sep, NULL as Oct, NULL as Nov,' +
        ' NULL as Dic, 0 as Tot, '
      'nombre, cast('#39'01'#39' as varchar(2)) as zona'
      
        'from estadis a join ptovta b on a.alm = b.clave and a.cia = b.ci' +
        'a'
      'where '
      
        '(tipo= :TIPO1 or tipo = :TIPO2) and anu = :ANU and codigo = :COD' +
        'IGO and a.cia = :CIA'
      
        'group by llave, codigo, alm, Ene, Feb, Mar, Abr, May, Jun, Jul, ' +
        'Ago, Sep, Oct, Nov, Dic, Tot, '
      'nombre, zona')
    Left = 275
    Top = 384
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_nombrestad: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select concepto, ncon from conceps where ncon = :IDCONCEPTO')
    Left = 213
    Top = 385
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDCONCEPTO'
        ParamType = ptUnknown
      end>
  end
  object dts_estadis: TDataSource
    AutoEdit = False
    DataSet = qry_estadis
    Left = 275
    Top = 416
  end
  object PopupMenu1: TPopupMenu
    Left = 120
    Top = 232
    object ExportaraExcel1: TMenuItem
      Caption = 'Exportar a ...'
      OnClick = ExportaraExcel1Click
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.xls'
    Filter = 'Archivos de Excel|*.xls|Todos los archivos|*.*'
    Left = 384
    Top = 248
  end
  object dts_zonini: TDataSource
    DataSet = qry_zonini
    Left = 455
    Top = 272
  end
  object qry_zonini: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by zona')
    Left = 456
    Top = 240
  end
  object qry_zonfin: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by zona')
    Left = 488
    Top = 240
  end
  object dts_zonfin: TDataSource
    DataSet = qry_zonfin
    Left = 487
    Top = 272
  end
  object qry_exist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri from inven'
      ' ')
    UpdateObject = uqry_exist
    Left = 424
    Top = 240
  end
  object dts_exist: TDataSource
    AutoEdit = False
    DataSet = qry_exist
    Left = 423
    Top = 272
  end
  object uqry_exist: TUpdateSQL
    Left = 424
    Top = 304
  end
  object qry_codigo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, costos, coston, fecalta,'
      'salvtas+salvtan+salfons+salfonn as ventas,'
      'salmays+salmayn as univtamay,'
      'precio, 0 as mub'
      'from inven where codigo = :CODIGO and cia = :CIA'
      ''
      ' ')
    Left = 181
    Top = 385
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_ventas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select sum(unidades) as univta from estadis'
      'where codigo = :CODIGO and '
      
        '(tipo = :TIPOVTA or tipo = :TIPOFON or tipo = :TIPOFID or tipo =' +
        ' :TIPOCEL)'
      
        'and (anu*100 + mes) between :PERIOINI and :PERIOFIN and cia = :C' +
        'IA')
    Left = 149
    Top = 385
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOFON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOFID'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOCEL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PERIOINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PERIOFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
